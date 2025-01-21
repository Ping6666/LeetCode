#include <vector>
#include <queue>
using std::vector, std::queue, std::max;

// Runtime: 259 ms (Beats 81.62 %), Memory: 297.52 MB (Beats 84.42 %).
// hint: find the diameter first (with bfs)

class Solution
{
private:
    int bfs(vector<vector<int>> &adj, int prev, int curr, int &idx)
    {
        int ans = 0;

        vector<bool> visited(adj.size(), false);
        queue<int> q;
        q.push(curr);

        while (!q.empty())
        {
            int l = q.size();

            for (int i = 0; i < l; i++)
            {
                idx = curr = q.front();
                // printf("idx %d\n", idx);
                visited[curr] = true;
                q.pop();

                for (const auto &next : adj[curr])
                {
                    if (!visited[next])
                    {
                        q.push(next);
                    }
                }
            }

            // good shxt
            if (!q.empty())
            {
                ans++;
            }
        }

        return ans;
    }

    int dfs(vector<vector<int>> &adj, int prev, int curr, int &idx)
    {
        int ans = 0;
        idx = curr;
        // printf("idx %d\n", idx);

        for (const auto &next : adj[curr])
        {
            if (next != prev)
            {
                ans = max(ans, bfs(adj, curr, next, idx) + 1);
            }
        }

        return ans;
    }

    int get_depth(vector<vector<int>> &edges)
    {
        int depth = 0, tmp = 0;
        int n = edges.size() + 1;

        if (n > 1)
        {
            vector<vector<int>> adj(n);
            for (const auto &e : edges)
            {
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }

            int start = -1;
            for (int i = 0; i < n; i++)
            {
                if (adj[i].size() == 1)
                {
                    start = i;
                    break;
                }
            }
            int real_start = -1;
            depth = bfs(adj, -1, start, real_start);
            // printf("bfs1 %d %d %d\n", start, real_start, depth);
            tmp = bfs(adj, -1, real_start, start);
            // printf("bfs2 %d %d\n", real_start, tmp);
            depth = max(depth, tmp);
            // printf("max %d\n\n", depth);
        }

        return depth;
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        int depth1 = get_depth(edges1);
        int depth2 = get_depth(edges2);
        // printf("get_depth %d %d\n", depth1, depth2);

        int best1 = (depth1 % 2) + (depth1 / 2);
        int best2 = (depth2 % 2) + (depth2 / 2);
        // printf("best %d %d\n", best1, best2);

        return max(1 + best1 + best2, max(depth1, depth2));
    }
};
