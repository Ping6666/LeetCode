class Solution:

    def maxTotalValue(self, value: list[int], decay: list[int], m: int) -> int:
        l = 1
        r = max(value)
        best_mid = 0

        # find the cutoff
        while l <= r:
            mid = (l + r) // 2

            count = 0
            for v, d in zip(value, decay):
                if v < mid:
                    continue

                # + 1 is counting for the first one
                c = (v - mid) // d + 1
                count += c
                if count >= m:
                    break

            if count >= m:
                l = mid + 1
                best_mid = mid
            else:
                r = mid - 1

        # C(x) = number of gains >= x
        # T = max x such that C(x) >= m

        tv = 0
        used = 0
        # count strictly greater the best_mid
        for v, d in zip(value, decay):
            if v > best_mid:
                c = (v - best_mid - 1) // d + 1
                tv += (v + v - (d * (c - 1))) * c // 2
                used += c

        # remain parts
        tv += (m - used) * best_mid
        return tv % (10**9 + 7)
