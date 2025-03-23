#include <vector>
#include <queue>
#include <algorithm>
using std::vector, std::priority_queue, std::pair, std::sort, std::max, std::greater;

// Runtime: 210 ms (Beats 62.42 %), Memory: 294.34 MB (Beats 38.86 %).

class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int heights_num = heights.size();
        int queries_num = queries.size();

        vector<int> ans(queries_num, -1);

        // height index, height, query index
        vector<vector<int>> table;

        int a, b, ah, bh;
        int min_height, min_height_idx;

        for (int i = 0; i < queries_num; i++)
        {
            a = queries[i][0];
            b = queries[i][1];
            ah = heights[a];
            bh = heights[b];

            // try to solve: heights[i] < heights[j]
            min_height_idx = max(a, b);
            if (min_height_idx != a)
            {
                ah += 1;
            }
            if (min_height_idx != b)
            {
                bh += 1;
            }

            min_height = max(ah, bh);
            table.push_back({min_height_idx, min_height, i});
        }

        sort(table.begin(), table.end());

        // height, query index
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int table_idx = 0, curr_height;
        for (int i = 0; i < heights_num; i++)
        {
            while (table_idx < queries_num && table[table_idx][0] <= i)
            {
                pq.push({table[table_idx][1], table[table_idx][2]});
                table_idx++;
            }

            curr_height = heights[i];

            while (!pq.empty())
            {
                auto t = pq.top();

                if (t.first <= curr_height)
                {
                    pq.pop();
                    ans[t.second] = i;
                }
                else
                {
                    break;
                }
            }
        }

        return ans;
    }
};
