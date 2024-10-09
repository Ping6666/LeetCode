#include <vector>
#include <queue>
using std::vector, std::priority_queue, std::pair, std::greater;

// Runtime: 562 ms (Beats 75.11 %), Memory: 242.14 MB (Beats 84.12 %).

class Solution
{
    // wrrrrrrrrrrrrrrrrrrry magic
    const int int_max = 2e9;

private:
    int
    dijkstra(const int &n, const int &src, const int &tgt, vector<vector<pair<int, int>>> &edges)
    {
        {
            vector<int> matrix(n, int_max);
            matrix[src] = 0;

            // smallest at top
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.emplace(0, src);

            while (!pq.empty())
            {
                auto [dist, node] = pq.top();
                pq.pop();

                if (matrix[node] < dist)
                {
                    continue;
                }

                for (const auto &[new_node, new_dist] : edges[node])
                {
                    if (matrix[new_node] > dist + new_dist)
                    {
                        matrix[new_node] = dist + new_dist;
                        pq.emplace(matrix[new_node], new_node);
                    }
                }
            }

            return matrix[tgt];
        }
    }

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
    {
        vector<vector<pair<int, int>>> flatten_edges(n);

        for (const auto &edge : edges)
        {
            if (edge[2] != -1)
            {
                flatten_edges[edge[0]].emplace_back(edge[1], edge[2]);
                flatten_edges[edge[1]].emplace_back(edge[0], edge[2]);
            }
        }

        int dist = dijkstra(n, source, destination, flatten_edges);
        if (dist < target)
        {
            // not satisfy shortest distance
            return {};
        }

        bool dist_match = dist == target;

        for (auto &edge : edges)
        {
            if (edge[2] != -1)
            {
                continue;
            }

            if (dist_match)
            {
                // do not want to change the shortest path
                edge[2] = int_max;
            }
            else
            {
                edge[2] = 1;
                flatten_edges[edge[0]].emplace_back(edge[1], edge[2]);
                flatten_edges[edge[1]].emplace_back(edge[0], edge[2]);

                dist = dijkstra(n, source, destination, flatten_edges);
                dist_match = dist <= target;

                if (dist_match)
                {
                    edge[2] += target - dist;
                }
            }
        }

        if (!dist_match)
        {
            return {};
        }

        return edges;
    }
};
