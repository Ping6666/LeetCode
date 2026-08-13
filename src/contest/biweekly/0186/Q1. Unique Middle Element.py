class Solution:

    def isMiddleElementUnique(self, nums: list[int]) -> bool:
        n = len(nums)

        i = n // 2
        v = nums[i]

        for j in range(n):
            if i == j:
                continue
            if nums[j] == v:
                return False
        return True
