class Solution:

    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 10**9 + 7
        m = r - l + 1

        up = [i for i in range(m)]
        down = [m - i - 1 for i in range(m)]

        for _ in range(n - 2):
            new_up = [0] * m
            new_down = [0] * m

            prefix = 0
            for j in range(m):
                new_up[j] = prefix
                prefix += down[j]
                if prefix >= MOD:
                    prefix -= MOD

            suffix = 0
            for j in range(m - 1, -1, -1):
                new_down[j] = suffix
                suffix += up[j]
                if suffix >= MOD:
                    suffix -= MOD

            up, down = new_up, new_down
        return (sum(up) + sum(down)) % MOD
