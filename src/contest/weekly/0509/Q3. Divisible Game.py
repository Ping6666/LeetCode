from math import isqrt

MOD = 10**9 + 7
NEG_INF = -10**18


class Solution:

    def divisibleGame(self, nums: list[int]) -> int:
        max_num = max(nums)

        primes = []
        for i in range(2, isqrt(max_num) + 2):
            is_prime = True
            for p in primes:
                if p * p > i:
                    break
                if i % p == 0:
                    is_prime = False
                    break
            if is_prime:
                primes.append(i)

        candidates = {2}
        for n in set(nums):
            r = n
            for p in primes:
                if p * p > r:
                    break
                if r % p == 0:
                    candidates.add(p)
                    while r % p == 0:
                        r //= p

            if r > 1:
                candidates.add(r)

        #

        d, k = NEG_INF, 0
        for p in candidates:  # speed up
            max_p_sum = p_sum = NEG_INF
            for n in nums:
                _n = n if n % p == 0 else -n
                p_sum = max(_n, p_sum + _n)
                max_p_sum = max(max_p_sum, p_sum)

            if max_p_sum > d:
                d = max_p_sum
                k = p
        return (d * k) % MOD
