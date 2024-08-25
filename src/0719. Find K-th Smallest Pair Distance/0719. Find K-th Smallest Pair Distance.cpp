#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 5 ms (Beats 90.64 %), Memory: 12.86 MB (Beats 44.69 %).
// Binary Search

class Solution
{
private:
    int countWithinDistance(vector<int> &nums, int d)
    {
        int n = nums.size();
        int l = 0, r = 0;

        int c = 0;
        for (r = 0; r < n; r++)
        {
            while (nums[r] - nums[l] > d)
            {
                l++;
            }

            c += r - l;
        }

        return c;
    }

public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0, r = nums[n - 1] - nums[0];

        int ans = 0;
        while (l <= r)
        {
            int m = l + (r - l) / 2;

            if (countWithinDistance(nums, m) < k)
            {
                l = m + 1;
            }
            else
            {
                ans = m;
                r = m - 1;
            }
        }

        return ans;
    }
};
