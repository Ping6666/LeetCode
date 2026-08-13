class Solution:

    def countValidSubarrays(self, nums: list[int], x: int) -> int:
        n = len(nums)
        nums_sum = [0] * n
        for i in range(n):
            for j in range(i, n):
                nums_sum[j] += nums[i]

        c = 0
        for i in range(n):
            for j in range(i, n):
                s = str(nums_sum[j])
                if int(s[0]) == x and int(s[-1]) == x:
                    c += 1
                nums_sum[j] -= nums[i]
        return c
