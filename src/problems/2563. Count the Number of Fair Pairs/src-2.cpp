#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 22 ms (Beats 99.09 %), Memory: 60.28 MB (Beats 97.26 %).

class Solution
{
private:
    long long compute(const vector<int> &nums, const int limits)
    {
        long long ans = 0;
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            while (l < r && nums[l] + nums[r] > limits)
            {
                r--;
            }
            if (nums[l] + nums[r] > limits)
            {
                break;
            }

            ans += (r - l);

            l++;
        }
        return ans;
    }

public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());

        return compute(nums, upper) - compute(nums, lower - 1);
    }
};
