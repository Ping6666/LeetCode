class Solution:

    def maxDigitRange(self, nums: list[int]) -> int:
        r_list = []

        max_range = 0
        for n in nums:
            n_str = str(n)
            n_str_list = list(n_str)
            min_n = int(min(n_str_list))
            max_n = int(max(n_str_list))
            # print(max_n, min_n)
            r_list.append(max_n - min_n)
            max_range = max(max_range, max_n - min_n)

        ans = 0
        for r, v in zip(r_list, nums):
            if r == max_range:
                ans += v
        return ans
