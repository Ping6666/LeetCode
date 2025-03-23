#include <vector>
#include <queue>
using std::vector, std::queue, std::max;

// ref.: LeetCode Editorial - Approach 1: Graph Coloring + Longest Shortest Path
// Runtime: 143 ms (Beats 65.55 %), Memory: 41.47 MB (Beats 92.44 %).

class Solution
{
private:
    bool isBipartite(const vector<vector<int>> &adj, const int &i,
                     vector<int> &colors)
    {
        for (const auto &a : adj[i])
        {
            if (colors[a] == colors[i])
            {
                return false;
            }

            if (colors[a] != -1)
            {
                continue;
            }

            colors[a] = (colors[i] + 1) % 2;

            if (!isBipartite(adj, a, colors))
            {
                return false;
            }
        }
        return true;
    }

    int getLongestShortestPath(const int &n, const vector<vector<int>> &adj, const int &i)
    {
        vector<bool> visited(n, false);

        queue<int> q;
        visited[i] = true;
        q.push(i);

        int s, distance = 0;
        while (!q.empty())
        {
            s = q.size();

            for (int ii = 0; ii < s; ii++)
            {
                int f = q.front();
                q.pop();

                for (const auto &a : adj[f])
                {
                    if (visited[a])
                    {
                        continue;
                    }

                    visited[a] = true;
                    q.push(a);
                }
            }
            distance++;
        }
        return distance;
    }

    int getNumberOfGroupsForComponent(const vector<vector<int>> &adj,
                                      const vector<int> &distances,
                                      const int &i,
                                      vector<bool> &visited)
    {
        int num_group = distances[i];
        visited[i] = true;

        for (const auto &a : adj[i])
        {
            if (visited[a])
            {
                continue;
            }

            num_group = max(num_group,
                            getNumberOfGroupsForComponent(adj, distances, a, visited));
        }
        return num_group;
    }

public:
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        for (const auto &e : edges)
        {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }

        vector<int> colors(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (colors[i] != -1)
            {
                continue;
            }

            colors[i] = 0;
            if (!isBipartite(adj, i, colors))
            {
                return -1;
            }
        }

        vector<int> distances(n);
        for (int i = 0; i < n; i++)
        {
            distances[i] = getLongestShortestPath(n, adj, i);
        }

        int max_group = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            max_group += getNumberOfGroupsForComponent(adj, distances, i, visited);
        }
        return max_group;
    }
};
