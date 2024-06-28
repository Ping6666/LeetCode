#include <vector>
using std::vector;

// Runtime: 93 ms (Beats 52.19 %), Memory: 62.42 MB (Beats 76.72 %).

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
private:
    void parseTree(TreeNode *root, vector<int> &inorder)
    {
        if (root == nullptr)
        {
            return;
        }

        parseTree(root->left, inorder);
        inorder.push_back(root->val);
        parseTree(root->right, inorder);
        return;
    }

    TreeNode *buildTree(const vector<int> &inorder, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }

        int mid = start + (end - start) / 2;

        TreeNode *root = new TreeNode(
            inorder[mid],
            buildTree(inorder, start, mid - 1),
            buildTree(inorder, mid + 1, end));
        return root;
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> inorder;
        parseTree(root, inorder);
        return buildTree(inorder, 0, inorder.size() - 1);
    }
};
