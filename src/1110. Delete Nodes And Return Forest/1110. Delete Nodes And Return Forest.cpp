#include <vector>
#include <unordered_set>
using std::vector, std::unordered_set;

// Runtime: 7 ms (Beats 98.33 %), Memory: 27.20 MB (Beats 23.69 %).
// store the del val in the unordered_set

// it can be done pass the ori. vector

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
    bool parser(vector<TreeNode *> &ans, unordered_set<int> &to_delete_set, TreeNode *root, bool do_push)
    {
        if (root == nullptr)
        {
            return false;
        }

        bool checker = false;

        if (to_delete_set.find(root->val) != to_delete_set.end())
        {
            // got val
            checker = true;
        }
        else if (do_push)
        {
            ans.push_back(root);
        }

        if (parser(ans, to_delete_set, root->left, checker))
        {
            root->left = nullptr;
        }

        if (parser(ans, to_delete_set, root->right, checker))
        {
            root->right = nullptr;
        }

        return checker;
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> ans;

        unordered_set<int> to_delete_set;
        for (auto d : to_delete)
        {
            to_delete_set.insert(d);
        }

        parser(ans, to_delete_set, root, true);

        return ans;
    }
};
