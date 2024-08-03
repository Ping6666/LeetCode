#include <limits.h>
#include <vector>
#include <queue>
using std::vector, std::priority_queue, std::pair, std::greater;

// Runtime: 28 ms (Beats 49.41 %), Memory: 20.26 MB (Beats 10.22 %).

class Solution
{
private:
    void dijkstra(int n, const vector<vector<pair<int, int>>> &edges, vector<int> &matrix, int i)
    {
        // smallest at top
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, i);

        while (!pq.empty())
        {
            auto [dist, city] = pq.top();
            pq.pop();

            if (matrix[city] < dist)
            {
                continue;
            }

            for (const auto &[_city, _weight] : edges[city])
            {
                if (matrix[_city] > dist + _weight)
                {
                    matrix[_city] = dist + _weight;
                    pq.emplace(matrix[_city], _city);
                }
            }
        }
    }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++)
        {
            matrix[i][i] = 0;
        }

        int from, to, weight;
        for (const auto &e : edges)
        {
            from = e[0];
            to = e[1];
            weight = e[2];

            adj[from].emplace_back(to, weight);
            adj[to].emplace_back(from, weight);
        }

        for (int i = 0; i < n; i++)
        {
            dijkstra(n, adj, matrix[i], i);
        }

        int ans = -1, min_count, curr_count;
        for (int i = 0; i < n; i++)
        {
            curr_count = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }

                if (matrix[i][j] <= distanceThreshold)
                {
                    curr_count++;
                }
            }

            if (ans == -1 || curr_count <= min_count)
            {
                min_count = curr_count;
                ans = i;
            }
        }

        return ans;
    }
};
