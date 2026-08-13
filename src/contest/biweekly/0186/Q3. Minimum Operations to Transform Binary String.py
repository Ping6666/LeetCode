# WA

def get_num_op(s1: str, s2: str):
    if s1 == "00":
        if s2 == "00":
            return 0
        elif s2 == "01":
            return 1
        elif s2 == "10":
            return 1
        elif s2 == "11":
            return 2
    elif s1 == "01":
        if s2 == "00":
            return 2
        elif s2 == "01":
            return 0
        elif s2 == "10":
            return 3
        elif s2 == "11":
            return 1
    elif s1 == "10":
        if s2 == "00":
            return 2
        elif s2 == "01":
            return 3
        elif s2 == "10":
            return 0
        elif s2 == "11":
            return 1
    elif s1 == "11":
        if s2 == "00":
            return 1
        elif s2 == "01":
            return 2
        elif s2 == "10":
            return 2
        elif s2 == "11":
            return 0
    return -1


class Solution:

    def minOperations(self, s1: str, s2: str) -> int:
        l = len(s1)
        if l == 1:
            if s1 == s2:
                return 0
            if s1 == "0":
                return 1
            else:
                return -1

        ans = 0
        i = 0
        while i < l:
            if s1[i] != s2[i]:
                if l - i >= 2:
                    ans += get_num_op(s1[i:i + 2], s2[i:i + 2])
                    i += 1
                else:
                    # fallback
                    ans += get_num_op(f"{s2[i-1]}{s1[i]}", s2[i - 1:i + 1])
            i += 1
        return ans
