#include <vector>
#include <queue>
#include <unordered_set>
using std::vector, std::queue, std::unordered_set;

// only one cycle
// Runtime: 0 ms (Beats 100.00 %), Memory: 15.04 MB (Beats 12.29 %).

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<unordered_set<int>> adj(n);
        for (const auto &e : edges)
        {
            adj[e[0] - 1].insert(e[1] - 1);
            adj[e[1] - 1].insert(e[0] - 1);
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() == 1)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int p = q.front();
            q.pop();

            int n = *adj[p].begin();
            adj[p].clear();

            adj[n].erase(p);
            if (adj[n].size() == 1)
            {
                q.push(n);
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (adj[edges[i][0] - 1].size() == 2 &&
                adj[edges[i][1] - 1].size() == 2)
            {
                return edges[i];
            }
        }
        return {};
    }
};
