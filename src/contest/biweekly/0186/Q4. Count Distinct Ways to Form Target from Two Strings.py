# TLE


def get_indice(s: str, c: chr):
    ans = []
    for i, cc in enumerate(s):
        if cc == c:
            ans.append(i)
    return ans


MOD = 10**9 + 7


class Solution:

    def interleaveCharacters(self, word1: str, word2: str, target: str) -> int:
        n, m = len(word1), len(word2)

        dp = [[0] * (m + 1) for _ in range(n + 1)]
        dp[0][0] = 1

        for c in target:
            ndp = [[0] * (m + 1) for _ in range(n + 1)]

            for j in range(m + 1):
                running = 0
                for i in range(n):
                    running += dp[i][j]
                    running %= MOD

                    if word1[i] == c:  # match the loop
                        ndp[i + 1][j] += running
                        ndp[i + 1][j] %= MOD

            for i in range(n + 1):
                running = 0
                for j in range(m):
                    running += dp[i][j]
                    running %= MOD

                    if word2[j] == c:  # match the loop
                        ndp[i][j + 1] += running
                        ndp[i][j + 1] %= MOD

            dp = ndp

        # skip the first (at least one)
        ans = 0
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                ans += dp[i][j]
                ans %= MOD
        return ans
