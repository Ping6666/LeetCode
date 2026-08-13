from math import sqrt, ceil

PRIME_TABLE = [2, 3, 5, 7, 11]

for i in range(12, 10**6 + 10):
    is_prime = True
    ii = ceil(sqrt(i)) + 1
    for j in PRIME_TABLE:
        if j > ii:
            break
        if i % j == 0:
            is_prime = False
            break
    if is_prime:
        PRIME_TABLE.append(i)

# ---

MOD = 10**9 + 7
NEG_INF = -10**18


class Solution:

    def divisibleGame(self, nums: list[int]) -> int:
        d, k = NEG_INF, 0
        for p in PRIME_TABLE:
            max_p_sum = p_sum = NEG_INF
            for n in nums:
                _n = n if n % p == 0 else -n
                p_sum = max(_n, p_sum + _n)
                max_p_sum = max(max_p_sum, p_sum)

            if max_p_sum > d:
                d = max_p_sum
                k = p
        return (d * k) % MOD
