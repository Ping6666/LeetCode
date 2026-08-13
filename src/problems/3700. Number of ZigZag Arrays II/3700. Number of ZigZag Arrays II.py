class Solution:

    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 10**9 + 7
        m = r - l + 1

        def mat_mul(A, B):
            size = len(A)
            C = [[0] * size for _ in range(size)]

            for i in range(size):
                Ci = C[i]
                Ai = A[i]
                for k in range(size):
                    if Ai[k]:
                        aik = Ai[k]
                        Bk = B[k]
                        for j in range(size):
                            Ci[j] = (Ci[j] + aik * Bk[j]) % MOD

            return C

        def mat_vec_mul(A, v):
            size = len(A)
            res = [0] * size

            for i in range(size):
                total = 0
                Ai = A[i]
                for j in range(size):
                    total += Ai[j] * v[j]
                res[i] = total % MOD

            return res

        # up[i] for arrays of length 2:
        # previous value < current value i
        up = [i for i in range(m)]

        # Build transition matrix A.
        #
        # new_up[j] = sum(down[i] for i < j)
        #           = sum(up[m - 1 - i] for i < j)
        #
        # So new_up[j] receives up[k] where k > m - 1 - j
        # equivalently: j + k >= m
        A = [[0] * m for _ in range(m)]
        for j in range(m):
            for k in range(m):
                if j + k >= m:
                    A[j][k] = 1

        power = n - 2

        while power:
            if power & 1:
                up = mat_vec_mul(A, up)
            A = mat_mul(A, A)
            power >>= 1

        # total = sum(up) + sum(down)
        # by symmetry, sum(up) == sum(down)
        return (2 * sum(up)) % MOD
