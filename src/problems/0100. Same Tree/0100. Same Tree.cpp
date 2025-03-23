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
    // Runtime: 0 ms (100.00 %), Memory: 9.9 MB (95.33 %).

    bool traversalTreeNode(TreeNode *Node1, TreeNode *Node2)
    {
        if (Node1 == NULL && Node2 == NULL)
        {
            return true;
        }
        else if (Node1 != NULL && Node2 != NULL && Node1->val == Node2->val)
        {
            // return true && left && right;
            return traversalTreeNode(Node1->left, Node2->left) && traversalTreeNode(Node1->right, Node2->right);
        }
        else
        {
            return false;
        }
    }

public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return traversalTreeNode(p, q);
    }
};
