#include <vector>
#include <unordered_set>
using std::vector, std::unordered_set;

class Solution
{
private:
    vector<int> parent;
    vector<int> depth;

    int _find(int node)
    {
        if (parent[node] == -1)
        {
            return node;
        }

        return parent[node] = _find(parent[node]);
    }

    void _union(int node1, int node2)
    {
        int root1 = _find(node1);
        int root2 = _find(node2);

        if (root1 == root2)
        {
            return;
        }

        if (depth[root1] < depth[root2])
        {
            int r = root1;
            root1 = root2;
            root2 = r;
        }

        parent[root2] = root1;

        if (depth[root1] == depth[root2])
        {
            depth[root1]++;
        }
    }

public:
    int numberOfComponents(vector<vector<int>> &properties, int k)
    {
        const int n = properties.size();

        parent.resize(n, -1);
        depth.resize(n, 0);

        vector<unordered_set<int>> properties_set(n);
        for (int i = 0; i < n; i++)
        {
            for (const auto &ii : properties[i])
            {
                properties_set[i].insert(ii);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }

                // do check
                int kk = 0;
                for (const auto &jj : properties_set[j])
                {
                    if (properties_set[i].find(jj) != properties_set[i].end())
                    {
                        // hit
                        kk++;
                        if (kk >= k)
                        {
                            break;
                        }
                    }
                }

                if (kk >= k)
                {
                    _union(i, j);
                }
            }
        }

        unordered_set<int> _set;
        for (int i = 0; i < n; i++)
        {
            _set.insert(_find(i));
        }
        return _set.size();
    }
};
