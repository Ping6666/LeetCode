#include <vector>
#include <unordered_set>
using std::vector, std::unordered_set;

// Runtime: 23 ms (Beats 92.91 %), Memory: 27.11 MB (Beats 8.86 %).
// Union Find

class Solution
{
private:
    class UnionFind
    {
    private:
        vector<int> parents;
        unordered_set<int> node_idx;

        int find(int node)
        {
            if (node_idx.find(node) == node_idx.end())
            {
                counter++;
                node_idx.insert(node);
            }

            if (parents[node] == -1)
            {
                return node;
            }

            // update
            parents[node] = find(parents[node]);
            return parents[node];
        }

    public:
        int counter;

        UnionFind(int n)
        {
            parents.resize(n, -1);
            counter = 0;
        }

        void unionNodes(int node1, int node2)
        {
            int root1 = find(node1);
            int root2 = find(node2);

            if (root1 == root2)
            {
                return;
            }

            parents[root1] = root2;
            counter--;
            return;
        }
    };

public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        UnionFind uf(20002);

        for (const auto &stone : stones)
        {
            uf.unionNodes(stone[0], stone[1] + 10001);
        }

        return n - uf.counter;
    }
};
