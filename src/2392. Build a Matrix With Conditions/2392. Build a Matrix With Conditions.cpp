#include <vector>
#include <queue>
using std::vector, std::queue;

// Runtime: 89 ms (Beats 86.76 %), Memory: 60.38 MB (Beats 83.10 %).
// Kahn's Algorithm

class Solution
{
private:
    vector<int> topoSort(vector<vector<int>> &edges, int n)
    {
        vector<vector<int>> adj(n + 1);
        vector<int> deg(n + 1);

        for (const auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            deg[e[1]]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            order.push_back(f);
            n--;

            for (const auto &a : adj[f])
            {
                deg[a]--;
                if (deg[a] == 0)
                {
                    q.push(a);
                }
            }
        }

        if (n != 0)
        {
            return {};
        }

        return order;
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        vector<int> rowSorted = topoSort(rowConditions, k);
        vector<int> colSorted = topoSort(colConditions, k);

        if (rowSorted.empty() || colSorted.empty())
        {
            return {};
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (rowSorted[i] == colSorted[j])
                {
                    ans[i][j] = rowSorted[i];
                }
            }
        }

        return ans;
    }
};
