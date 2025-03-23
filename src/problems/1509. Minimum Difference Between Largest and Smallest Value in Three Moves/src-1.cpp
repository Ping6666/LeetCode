#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 61 ms (Beats 86.29 %), Memory: 38.64 MB (Beats 80.72 %).

class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();

        if (n <= 4)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int diff = nums.back() - nums.front();

        if (diff <= 0)
        {
            return 0;
        }

        int arr1[6] = {
            nums[3] - nums[2],
            nums[2] - nums[1],
            nums[1] - nums[0],
            //
            nums[n - 1] - nums[n - 2],
            nums[n - 2] - nums[n - 3],
            nums[n - 3] - nums[n - 4],
        };

        int arr2[4] = {
            arr1[0] + arr1[1] + arr1[2],
            arr1[1] + arr1[2] + arr1[3],
            arr1[2] + arr1[3] + arr1[4],
            arr1[3] + arr1[4] + arr1[5],
        };
        sort(arr2, arr2 + 4);

        diff -= arr2[3];

        if (diff <= 0)
        {
            return 0;
        }
        return diff;
    }
};
