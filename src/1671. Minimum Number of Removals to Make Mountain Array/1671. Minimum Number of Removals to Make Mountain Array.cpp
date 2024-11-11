#include <vector>
#include <algorithm>
#include <limits.h>
using std::vector, std::reverse, std::lower_bound, std::min;

// Runtime: 2 ms (Beats 92.42 %), Memory: 15.13 MB (Beats 31.84 %).

// ref. LeetCode Editorial - Approach 2: LIS Using Binary Search

class Solution
{
private:
    vector<int> getLISLen(vector<int> &v)
    {
        // Longest Increasing Subsequence Length

        // lower_bound (the range need to be pre-sorted)
        // an iterator pointing to the first element in the range [first,last) which does not compare less than val.

        int n = v.size();
        vector<int> lis_len(n, 1);
        vector<int> lis = {v[0]};

        int idx;
        for (int i = 1; i < n; i++)
        {
            idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();

            if (idx == lis.size())
            {
                // no hit
                lis.push_back(v[i]);
            }
            else
            {
                lis[idx] = v[i];
            }

            lis_len[i] = lis.size();
        }

        return lis_len;
    }

public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lis, lds;

        lis = getLISLen(nums);

        reverse(nums.begin(), nums.end());
        lds = getLISLen(nums);
        reverse(lds.begin(), lds.end());

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (lis[i] > 1 && lds[i] > 1)
            {
                ans = min(ans, n - lis[i] - lds[i] + 1);
            }
        }

        return ans;
    }
};
