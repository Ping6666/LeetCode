// Runtime: 0 ms (Beats 100.00 %), Memory: 10.03 MB (Beats 77.24 %).

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int sumTree(TreeNode *root, int v)
    {
        if (root == nullptr)
        {
            return v;
        }

        root->val += sumTree(root->right, v);
        return sumTree(root->left, root->val);
    }

    TreeNode *bstToGst(TreeNode *root)
    {
        sumTree(root, 0);
        return root;
    }
};
