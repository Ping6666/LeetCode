struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Runtime: 0 ms (Beats 100.00 %), Memory: 22.10 MB (Beats 67.37 %).

class Solution
{
private:
    int dfs(TreeNode *root, int depth, int &deepest_leaves, TreeNode *&ans)
    {
        if (!root)
        {
            return -1;
        }

        int l = dfs(root->left, depth + 1, deepest_leaves, ans);
        int r = dfs(root->right, depth + 1, deepest_leaves, ans);
        // printf("%d %d %d\n", root->val, l, r);

        if (depth > deepest_leaves)
        {
            // printf("set %d\n", root->val);
            deepest_leaves = depth;
            ans = root;
        }
        if (l == r && l >= deepest_leaves)
        {
            // printf("set %d\n", root->val);
            deepest_leaves = l;
            ans = root;
        }

        if (l == -1 && r == -1)
        {
            return depth;
        }
        return max(l, r);
    }

public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        int deepest_leaves = 0;
        TreeNode *ans = root;
        dfs(root, 0, deepest_leaves, ans);
        return ans;
    }
};
