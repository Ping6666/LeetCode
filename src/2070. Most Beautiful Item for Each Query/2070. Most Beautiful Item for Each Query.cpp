#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 55 ms (Beats 68.85 %), Memory: 99.16 MB (Beats 36.49 %).

class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        int n = queries.size();
        int items_n = items.size();

        sort(items.begin(), items.end(), [](vector<int> &lhs, vector<int> &rhs)
             { return lhs[0] < rhs[0]; });

        vector<int> ans(n, 0);
        vector<vector<int>> queries_table(n, vector<int>(2, 0));

        for (int i = 0; i < n; i++)
        {
            queries_table[i][0] = queries[i];
            queries_table[i][1] = i;
        }

        sort(queries_table.begin(), queries_table.end(), [](vector<int> &lhs, vector<int> &rhs)
             { return lhs[0] < rhs[0]; });

        int item_idx = 0, max_beauty = 0;
        for (int i = 0; i < n; i++)
        {
            int query = queries_table[i][0];
            int idx = queries_table[i][1];

            while (item_idx < items_n && items[item_idx][0] <= query)
            {
                max_beauty = max(max_beauty, items[item_idx][1]);
                item_idx++;
            }

            ans[idx] = max_beauty;
        }

        return ans;
    }
};
