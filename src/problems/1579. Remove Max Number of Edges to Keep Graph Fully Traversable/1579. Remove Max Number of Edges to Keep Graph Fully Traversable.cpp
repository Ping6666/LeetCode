#include <vector>
using std::vector;

// Runtime: 329 ms (Beats 92.38 %), Memory: 142.40 MB (Beats 95.92 %).
// Union Find

class UnionFind
{

public:
    vector<int> parent, child_count;
    int used_leaf;

    // vector as a tree struct
    // use parent as leaf's parent and the child_count as the leaf's sub-leaf counts

    UnionFind(int n)
    {
        used_leaf = n;
        parent.resize(n);
        child_count.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            // self loop
            parent[i] = i;
        }
        return;
    }

    /*
     * get the root of given idx
     */
    int find(int i)
    {
        if (parent[i] != i)
        {
            // find and update
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    bool unite(int i, int j)
    {
        int ii = find(i), jj = find(j);
        if (ii == jj)
        {
            return false;
        }

        if (child_count[ii] < child_count[jj])
        {
            // do swap
            int c = ii;
            ii = jj;
            jj = c;
        }

        parent[jj] = parent[ii];
        child_count[ii] += child_count[jj];
        used_leaf--;
        return true;
    }

    bool traversable()
    {
        return used_leaf == 1;
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        UnionFind alice(n), bob(n);

        int edges_counts = edges.size();
        int edges_used = 0;

        bool a, b;

        for (int i = 0; i < edges_counts; i++)
        {
            if (edges[i][0] == 3)
            {
                a = alice.unite(edges[i][1] - 1, edges[i][2] - 1);
                b = bob.unite(edges[i][1] - 1, edges[i][2] - 1);
                if (a || b)
                {
                    edges_used++;
                }
            }
        }

        for (int i = 0; i < edges_counts; i++)
        {
            if (edges[i][0] == 1)
            {
                if (alice.unite(edges[i][1] - 1, edges[i][2] - 1))
                {
                    edges_used++;
                }
            }
            else if (edges[i][0] == 2)
            {
                if (bob.unite(edges[i][1] - 1, edges[i][2] - 1))
                {
                    edges_used++;
                }
            }
        }

        // printf("%d %d\n", edges_counts, edges_used);
        if (alice.traversable() && bob.traversable())
        {
            return edges_counts - edges_used;
        }

        return -1;
    }
};
