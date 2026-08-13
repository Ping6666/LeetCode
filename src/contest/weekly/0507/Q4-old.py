from heapq import *


class Solution:

    def maxTotalValue(self, value: list[int], decay: list[int], m: int) -> int:
        pq = []
        for v, d in zip(value, decay):
            # max heap
            heappush(pq, (-1 * v, d))

        tv = 0

        v, d = heappop(pq)

        i = 0
        while i < m:
            if v >= 0:  # max heap
                break

            tv -= v

            # value[i] - decay[i] * (t - 1)
            v, d = heappushpop(pq, (v + d, d))

            i += 1

        return int(tv % (1e9 + 7))
