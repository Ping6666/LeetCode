/*
Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/

#include <stddef.h>

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
    // Runtime: 4 ms (80.61 %), Memory: 16.2 MB (99.06 %).

    bool traversalTreeNode(TreeNode *Node1, TreeNode *Node2)
    {
        if (Node1 == NULL && Node2 == NULL)
        {
            return true;
        }
        else if (Node1 != NULL && Node2 != NULL && Node1->val == Node2->val)
        {
            // return true && left && right;
            return traversalTreeNode(Node1->left, Node2->right) && traversalTreeNode(Node1->right, Node2->left);
        }
        else
        {
            return false;
        }
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        else
            return traversalTreeNode(root->left, root->right);
    }
};
