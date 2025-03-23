#include <limits.h>
#include <vector>
#include <queue>
#include <unordered_map>
using std::vector, std::queue, std::unordered_map, std::pair, std::max;

// Runtime: 123 ms (Beats 71.95 %), Memory: 154.65 MB (Beats 68.74 %).

class Solution
{
private:
    bool dfs(const vector<vector<int>> &adj, unordered_map<int, int> &bob_path,
             vector<bool> &visited, int i, int t)
    {
        bob_path[i] = t;
        visited[i] = true;

        if (i == 0)
        {
            return true;
        }

        for (const auto &a : adj[i])
        {
            if (!visited[a])
            {
                if (dfs(adj, bob_path, visited, a, t + 1))
                {
                    return true;
                }
            }
        }

        bob_path.erase(i);
        return false;
    }

public:
    int mostProfitablePath(vector<vector<int>> &edges, int bob,
                           vector<int> &amount)
    {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (const auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_map<int, int> bob_path;
        vector<bool> visited(n, false);
        dfs(adj, bob_path, visited, bob, 0);

        visited.assign(n, false);

        queue<pair<int, int>> q;
        q.push({0, 0});

        int t = 0, ans = INT_MIN;
        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                auto f = q.front();
                q.pop();
                int j = f.first, b = f.second;

                visited[j] = true;
                if (bob_path.find(j) != bob_path.end())
                {
                    if (bob_path[j] == t)
                    {
                        // reach the node simultaneously
                        b += (amount[j] / 2);
                    }
                    else if (t < bob_path[j])
                    {
                        // Alice first
                        b += amount[j];
                    }
                }
                else
                {
                    // only Alice will get here
                    b += amount[j];
                }

                for (const auto &a : adj[j])
                {
                    if (!visited[a])
                    {
                        q.push({a, b});
                    }
                }

                // NOTE check not starting from leaf is very important
                if (adj[j].size() == 1 && j != 0)
                {
                    ans = max(ans, b);
                }
            }

            t++;
        }

        return ans;
    }
};
