#include <vector>
using namespace std;

// Maximum Subarray Problem

class Solution
{
    // Kadane's algorithm

    // Time complexity: O( n )
    // Runtime: 96 ms (92.44 %), Memory: 67.7 MB (91.39 %).

public:
    int maxSubArray(vector<int> &nums)
    {
        int Sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > Sum)
            {
                Sum = nums[i];
            }
        }
        if (Sum <= 0)
        {
            return Sum;
        }
        int tmpSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            tmpSum += nums[i];
            if (tmpSum <= 0)
            {
                tmpSum = 0;
            }
            else if (tmpSum > Sum)
            {
                Sum = tmpSum;
            }
        }
        return Sum;
    }
};

/*
class Solution
{
    // Divide and conquer

    // Time complexity: O( n×log(n) )
    // Runtime: 120 ms (52.54 %), Memory: 67.6 MB (99.72 %).

    int crossSum(vector<int> &nums, int left, int right)
    {
        int middle = (left + right) / 2;
        int realSum = nums[middle], tmpSum = realSum;
        for (int i = middle - 1; i >= left; i--)
        {
            // sum of left part
            tmpSum += nums[i];
            if (realSum < tmpSum)
                realSum = tmpSum;
        }
        tmpSum = realSum;
        for (int i = middle + 1; i <= right; i++)
        {
            // sum of right part
            tmpSum += nums[i];
            if (realSum < tmpSum)
                realSum = tmpSum;
        }
        return realSum;
    }

    int maxSum(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return nums[left];
        int middle = (left + right) / 2;
        return max(max(maxSum(nums, left, middle), maxSum(nums, middle + 1, right)), crossSum(nums, left, right));
    }

public:
    int maxSubArray(vector<int> &nums)
    {
        return maxSum(nums, 0, nums.size() - 1);
    }
};
*/
