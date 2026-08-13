from typing import List
from math import floor, ceil


def op1(n, k):
    return n * k


def op2(n, k):
    if n >= 0:
        return floor(n / k)
    return ceil(n / k)


def maxSubarraySum_op(nums: List[int], k, op) -> int:
    _num = nums[0]
    _num_k = op(_num, k)

    p_no, c_no = _num, _num
    p_in, c_in = _num_k, _num_k
    p_after, c_after = _num, _num

    ans_no = _num
    ans_in = _num_k
    ans_after = _num

    for n in nums[1:]:
        n_k = op(n, k)

        # no
        c_no = max(n, p_no + n)
        ans_no = max(ans_no, c_no)

        # in
        c_in = max(n_k, p_in + n_k, p_no + n_k)
        ans_in = max(ans_in, c_in)

        # after
        c_after = max(p_after + n, p_in + n)
        ans_after = max(ans_after, c_after)

        p_no = c_no
        p_in = c_in
        p_after = c_after

    return max(ans_no, ans_in, ans_after)


class Solution:

    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        # nums_op1 = [k * n for n in nums]
        # nums_op2 = [floor(n / k) if n >= 0 else ceil(n / k) for n in nums]

        return max(maxSubarraySum_op(nums, k, op1),
                   maxSubarraySum_op(nums, k, op2))
