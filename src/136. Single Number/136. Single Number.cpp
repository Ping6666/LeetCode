#include <stdio.h>
#include <vector>
using std::vector;

class Solution
{
    // Runtime: 7 ms (Beats 96.41 %), Memory: 19.03 MB (Beats 98.67 %).

public:
    int singleNumber(vector<int> &nums)
    {
        int n = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            n ^= nums[i];
        }

        printf("%d\n", n);
        return n;
    }
};

int main()
{
    vector<int> nums;

    nums = {2, 2, 1};
    Solution().singleNumber(nums);

    nums = {4, 1, 2, 1, 2};
    Solution().singleNumber(nums);

    nums = {1};
    Solution().singleNumber(nums);

    return 0;
}
