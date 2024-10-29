struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <queue>
using std::queue, std::pair;

// Runtime: 0 ms (Beats 100.00 %), Memory: 14.73 MB (Beats 6.32 %).

// constraints: unique node values

bool same(TreeNode *a, TreeNode *b)
{
    if (!a && !b)
    {
        // both are nullptr
        return true;
    }
    else if (!a || !b)
    {
        // one is nullptr
        return false;
    }

    return a->val == b->val;
}

class Solution
{
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        queue<pair<TreeNode *, TreeNode *>> table;
        table.emplace(root1, root2);

        while (!table.empty())
        {
            auto t = table.front();
            table.pop();

            if (!same(t.first, t.second))
            {
                return false;
            }

            if (t.first && t.second)
            {
                if (same(t.first->left, t.second->left) && same(t.first->right, t.second->right))
                {
                    table.emplace(t.first->left, t.second->left);
                    table.emplace(t.first->right, t.second->right);
                }
                else
                {
                    table.emplace(t.first->left, t.second->right);
                    table.emplace(t.first->right, t.second->left);
                }
            }
        }

        return true;
    }
};
