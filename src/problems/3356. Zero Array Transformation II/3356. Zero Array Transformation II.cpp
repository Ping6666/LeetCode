#include <vector>
using std::vector, std::max;

// Runtime: 2 ms (Beats 94.52 %), Memory: 322.81 MB (Beats 94.01 %).
// ref.: LeetCode Editorial - Approach 2: Line Sweep

class Solution
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        const int n = nums.size();
        const int q = queries.size();

        int prefix_sum = 0;
        int nums_idx = 0, queries_idx = 0;

        vector<int> prefix(n + 1, 0);
        for (; nums_idx < n; nums_idx++)
        {
            // try to see next
            while (prefix_sum + prefix[nums_idx] < nums[nums_idx])
            {
                if (queries_idx >= q)
                {
                    return -1;
                }

                int l = queries[queries_idx][0], r = queries[queries_idx][1], v = queries[queries_idx][2];
                queries_idx++;

                if (r >= nums_idx)
                {
                    prefix[max(l, nums_idx)] += v;
                    prefix[r + 1] -= v;
                }
            }

            // see next
            prefix_sum += prefix[nums_idx];
        }
        return queries_idx;
    }
};
