#include <vector>
#include <queue>
#include <unordered_map>
using std::vector, std::queue, std::unordered_map, std::pair;

// TLE

struct Node
{
    int val;
    unordered_map<int, int> children;

    Node(int v) : val(v) {};
};

class Solution
{
private:
    void dfs(const vector<Node *> &node_table, Node *node,
             int prev_dist, vector<int> &dist)
    {
        if (!node)
        {
            return;
        }

        int v = node->val;
        dist[v] = prev_dist;

        for (const auto c : node->children)
        {
            dfs(node_table, node_table[c.first], prev_dist + c.second, dist);
        }
    }

public:
    vector<int> treeQueries(int n, vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto edge : edges)
        {
            adj[edge[0] - 1].push_back({edge[1] - 1, edge[2]});
            adj[edge[1] - 1].push_back({edge[0] - 1, edge[2]});
        }

        vector<Node *> node_table(n);

        Node *root = new Node(0);
        node_table[0] = root;

        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            auto f = q.front();
            q.pop();

            for (const auto nn : adj[f])
            {
                if (!node_table[nn.first])
                {
                    Node *_node = new Node(nn.first);
                    node_table[nn.first] = _node;

                    node_table[f]->children[nn.first] = nn.second;
                    q.push(nn.first);
                }
            }
        }

        vector<int> dist(n, 0);
        dist[0] = 0;

        dfs(node_table, root, 0, dist);

        vector<int> ans;
        for (const auto &q : queries)
        {
            if (q[0] == 1)
            {
                // update
                int _n1 = q[1] - 1;
                int _n2 = q[2] - 1;
                Node *n1 = node_table[_n1];
                Node *n2 = node_table[_n2];

                if (n1->children.find(_n2) != n1->children.end())
                {
                    // n1 -> n2
                    n1->children[_n2] = q[3];
                    dfs(node_table, n2, dist[_n1] + q[3], dist);
                }
                else
                // if (n2->children.find(_n1) != n2->children.end())
                {
                    // n2 -> n1
                    n2->children[_n1] = q[3];
                    dfs(node_table, n1, dist[_n2] + q[3], dist);
                }
            }
            else
            {
                // compute shortest path distance
                ans.push_back(dist[q[1] - 1]);
            }
        }
        return ans;
    }
};
