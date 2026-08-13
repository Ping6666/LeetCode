class Solution:

    def maxSum(self, nums: list[int], k: int, mul: int) -> int:
        sorted_nums = sorted(nums, reverse=True)
        ans = 0
        for i in range(k):
            n = sorted_nums[i]
            if mul > 1:
                ans += n * mul
                mul -= 1
            else:
                ans += n
        return ans
