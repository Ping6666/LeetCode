#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 117.40 MB (Beats 97.12 %).

class Solution
{
private:
    vector<int> parent;
    vector<int> depth;
    vector<int> _size;

    int find(int node)
    {
        if (parent[node] == -1)
        {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void _union(int node1, int node2)
    {
        int root1 = find(node1);
        int root2 = find(node2);

        if (root1 == root2)
        {
            _size[root1]++;
            return;
        }

        if (depth[root1] < depth[root2])
        {
            // swap
            int r = root1;
            root1 = root2;
            root2 = r;
        }

        parent[root2] = root1;
        _size[root1] += _size[root2] + 1;
        _size[root2] = 0;

        if (depth[root1] == depth[root2])
        {
            depth[root1]++;
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        parent.resize(n, -1);
        depth.resize(n, 0);
        _size.resize(n, 0);

        for (const auto &e : edges)
        {
            _union(e[0], e[1]);
        }

        // for (int i = 0; i < n; i++)
        // {
        //     printf("%d %d %d %d\n", i, parent[i], depth[i], _size[i]);
        // }

        vector<int> node_count(n, 0);
        for (int i = 0; i < n; i++)
        {
            int p = find(i);
            if (p == -1)
            {
                node_count[i]++;
            }
            else
            {
                node_count[p]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int r = node_count[i];
            if (r != 0)
            {
                if (_size[i] == ((r - 1) * r / 2))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
