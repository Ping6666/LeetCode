#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 10.18 MB (Beats 44.35 %).

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
    void postorder(TreeNode *root, vector<int> &vec)
    {
        if (!root)
        {
            return;
        }

        postorder(root->left, vec);
        postorder(root->right, vec);

        vec.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        postorder(root, vec);

        return vec;
    }
};
