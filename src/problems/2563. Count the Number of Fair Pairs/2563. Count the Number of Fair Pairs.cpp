#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 23 ms (Beats 98.81 %), Memory: 60.28 MB (Beats 80.83 %).

class Solution
{
private:
    long long count(vector<int> &nums, int bound)
    {
        long long ans = 0;
        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            int s = nums[l] + nums[r];

            if (s < bound)
            {
                ans += r - l;
                l++;
            }
            else
            {
                r--;
            }
        }

        return ans;
    }

public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());

        return count(nums, upper + 1) - count(nums, lower);
    }
};
