#include <vector>
#include <algorithm>
#include <queue>
using std::vector, std::sort, std::priority_queue, std::pair, std::greater;

// Runtime: 79 ms (Beats 90.94 %), Memory: 40.00 MB (Beats 81.16 %).

class Solution
{
public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        vector<vector<int>> DIR = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        const int k = queries.size();
        const int m = grid.size();
        const int n = grid[0].size();

        vector<pair<int, int>> queries_table;
        for (int i = 0; i < k; i++)
        {
            queries_table.push_back({queries[i], i});
        }
        sort(queries_table.begin(), queries_table.end());

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        int count = 0;
        vector<int> ans(k);
        for (auto [q, i] : queries_table)
        {
            while (!pq.empty() && pq.top().first < q)
            {
                auto [qq, pos] = pq.top();
                pq.pop();

                count++;

                int x = pos.first, y = pos.second;

                for (int j = 0; j < 4; j++)
                {
                    int xx = x + DIR[j][0];
                    int yy = y + DIR[j][1];

                    if (0 <= xx && xx < m && 0 <= yy && yy < n && !visited[xx][yy])
                    {
                        pq.push({grid[xx][yy], {xx, yy}});
                        visited[xx][yy] = true;
                    }
                }
            }

            ans[i] = count;
        }
        return ans;
    }
};
