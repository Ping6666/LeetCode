#include <vector>
#include <algorithm>
using std::vector, std::sort, std::pair;

// Runtime: 78 ms (Beats 95.27 %), Memory: 135.27 MB (Beats 91.89 %).

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int n = nums.size();

        vector<pair<int, int>> table;
        for (int i = 0; i < n; i++)
        {
            table.push_back({nums[i], i});
        }

        sort(table.begin(), table.end());

        vector<int> ans(n, -1);

        int prev = -1, idx_len;
        vector<int> idx;
        for (int i = 0; i < n; i++)
        {
            if (prev != -1 && prev + limit >= table[i].first)
            {
                prev = table[i].first;
                idx.push_back(table[i].second);
            }
            else
            {
                idx_len = idx.size();
                if (idx_len > 0)
                {
                    sort(idx.begin(), idx.end());

                    for (int j = 0; j < idx_len; j++)
                    {
                        ans[idx[j]] = table[(i - 1) - (idx_len - 1) + j].first;
                    }
                }

                prev = table[i].first;

                idx.clear();
                idx.push_back(table[i].second);
            }
        }

        idx_len = idx.size();
        if (idx_len > 0)
        {
            sort(idx.begin(), idx.end());

            for (int j = 0; j < idx_len; j++)
            {
                ans[idx[j]] = table[(n - 1) - (idx_len - 1) + j].first;
            }
        }

        return ans;
    }
};
