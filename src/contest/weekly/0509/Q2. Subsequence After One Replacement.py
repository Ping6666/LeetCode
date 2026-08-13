class Solution:

    def canMakeSubsequence(self, s: str, t: str) -> bool:
        n = len(s)

        dp0, dp1 = 0, 0
        for _t, in t:
            if dp1 < n and s[dp1] == _t:
                # match do nothing
                dp1 += 1
            dp1 = max(dp1, dp0 + 1)
            if dp0 < n and s[dp0] == _t:
                # match do nothing
                dp0 += 1

        if dp0 >= n or dp1 >= n:
            return True
        return False
