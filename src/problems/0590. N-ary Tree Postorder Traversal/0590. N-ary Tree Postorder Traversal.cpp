#include <vector>
using std::vector;

// Runtime: 6 ms (Beats 98.00 %), Memory: 15.07 MB (Beats 80.43 %).

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
private:
    void postorder_traversal(Node *root, vector<int> &vec)
    {
        if (!root)
        {
            return;
        }

        for (const auto &n : root->children)
        {
            postorder_traversal(n, vec);
        }

        vec.push_back(root->val);
        return;
    }

public:
    vector<int> postorder(Node *root)
    {
        vector<int> vec;
        postorder_traversal(root, vec);

        return vec;
    }
};
