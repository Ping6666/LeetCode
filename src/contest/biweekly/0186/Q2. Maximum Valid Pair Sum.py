class Solution:

    def maxValidPairSum(self, nums: list[int], k: int) -> int:
        n = len(nums)

        dec_list = [(nums[-1], n - 1)]

        for i in reversed(range(n - 1)):
            if nums[i] > dec_list[0][0]:
                dec_list.insert(0, (nums[i], i))

        ans = nums[0] + nums[-1]
        for i in range(n - 1):

            # speed up
            while len(dec_list) > 0 and dec_list[0][-1] - i < k:
                dec_list.pop(0)
            if len(dec_list) <= 0:
                break

            for v, j in dec_list:
                if j - i < k:
                    continue
                ans = max(ans, v + nums[i])
                continue
        return ans
