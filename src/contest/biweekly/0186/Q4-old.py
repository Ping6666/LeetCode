# TLE


def get_indice(s: str, c: chr):
    ans = []
    for i, cc in enumerate(s):
        if cc == c:
            ans.append(i)
    return ans


MOD = 10**9 + 7


class Solution:

    def interleaveCharacters(
        self,
        word1: str,
        word2: str,
        target: str,
        from1: bool = False,
        from2: bool = False,
    ) -> int:
        ans = 0

        if len(target) == 0:
            return ans

        c = target[0]
        do_plus = len(target) == 1

        # from word1
        word1_indice = get_indice(word1, c)
        for i in word1_indice:
            if do_plus:
                if from2:
                    ans += 1
            else:
                ans += self.interleaveCharacters(
                    word1[i + 1:],
                    word2,
                    target[1:],
                    True,
                    from2,
                )
                ans %= MOD

        # from word2
        word2_indice = get_indice(word2, c)
        for i in word2_indice:
            if do_plus:
                if from1:
                    ans += 1
            else:
                ans += self.interleaveCharacters(
                    word1,
                    word2[i + 1:],
                    target[1:],
                    from1,
                    True,
                )
                ans %= MOD

        return ans % MOD
