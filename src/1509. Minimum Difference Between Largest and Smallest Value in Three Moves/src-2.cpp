#include <vector>
#include <algorithm>
using std::vector, std::sort, std::nth_element;

// Runtime: 49 ms (Beats 97.28 %), Memory: 37.55 MB (Beats 99.09 %).

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

        nth_element(nums.begin(), nums.begin() + 4, nums.end());
        nth_element(nums.begin() + 4, nums.end() - 4, nums.end());
        sort(nums.begin(), nums.begin() + 4);
        sort(nums.end() - 4, nums.end());

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
