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

#include <vector>
using namespace std;

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
    // Runtime: 0 ms (100.00 %), Memory: 9.1 MB (12.78 %).

    vector<int> traversalTreeNode(TreeNode *nowNode)
    {
        vector<int> ansVector;
        if (nowNode == NULL)
            return ansVector;
        int nowVal = nowNode->val;
        vector<int> leftVector = traversalTreeNode(nowNode->left);
        vector<int> rightVector = traversalTreeNode(nowNode->right);
        ansVector.reserve(leftVector.size() + 1 + rightVector.size());
        ansVector.insert(ansVector.end(), leftVector.begin(), leftVector.end());
        ansVector.insert(ansVector.end(), rightVector.begin(), rightVector.end());
        ansVector.insert(ansVector.end(), nowVal);
        return ansVector;
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        return traversalTreeNode(root);
    }
};
