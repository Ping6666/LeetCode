struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 28.04 MB (Beats 90.13 %).

class Solution
{
private:
    TreeNode *constructSingleFromPrePost(vector<int> &preorder, const int pre_start, const int pre_end,
                                         vector<int> &postorder, const int post_start, const int post_end)
    {
        // preorder  = [Root,  Left, Right]
        // postorder = [Left, Right,  Root]

        TreeNode *root = new TreeNode(preorder[pre_start]);

        if (pre_start == pre_end)
        {
            return root;
        }

        int l_post_end = post_start;
        while (postorder[l_post_end] != preorder[pre_start + 1])
        {
            l_post_end++;
        }
        int l_pre_end = pre_start + 1 + (l_post_end - post_start);

        root->left = constructSingleFromPrePost(preorder, pre_start + 1, l_pre_end,
                                                postorder, post_start, l_post_end);

        if (l_pre_end + 1 <= pre_end)
        {
            root->right = constructSingleFromPrePost(preorder, l_pre_end + 1, pre_end,
                                                     postorder, l_post_end + 1, post_end - 1);
        }

        return root;
    }

public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int n = preorder.size();
        return constructSingleFromPrePost(preorder, 0, n - 1,
                                          postorder, 0, n - 1);
    }
};
