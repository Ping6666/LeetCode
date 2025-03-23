#include <vector>
using std::vector;

// Runtime: 9 ms (Beats 94.81 %), Memory: 204.85 MB (Beats 83.77 %).

class Solution
{
private:
    int find(vector<int> &parent, int node)
    {
        if (parent[node] == -1)
        {
            return node;
        }

        return parent[node] = find(parent, parent[node]);
    }

    void _union(vector<int> &parent, vector<int> &depth,
                int node1, int node2)
    {
        int root1 = find(parent, node1);
        int root2 = find(parent, node2);

        if (root1 == root2)
        {
            return;
        }

        if (depth[root1] < depth[root2])
        {
            int t = root1;
            root1 = root2;
            root2 = t;
        }

        parent[root2] = root1;

        if (depth[root1] == depth[root2])
        {
            depth[root1]++;
        }
    }

public:
    vector<int> minimumCost(int n, vector<vector<int>> &edges,
                            vector<vector<int>> &query)
    {
        vector<int> parent(n, -1);
        vector<int> depth(n, 0);

        for (const auto &e : edges)
        {
            _union(parent, depth, e[0], e[1]);
        }

        // bitwise all one
        vector<int> _cost(n, -1);
        for (const auto &e : edges)
        {
            _cost[find(parent, e[0])] &= e[2];
        }

        vector<int> ans;
        for (const auto &q : query)
        {
            if (find(parent, q[0]) != find(parent, q[1]))
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(_cost[find(parent, q[0])]);
            }
        }
        return ans;
    }
};
