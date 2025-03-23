
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
#include <algorithm>
using std::vector, std::sort;

// Runtime: 824 ms (Beats 9.48 %), Memory: 173.62 MB (Beats 5.08 %).
// see 2641

class Solution
{
private:
    void bfs(TreeNode *root, vector<long long> &level_sum, int level)
    {
        if (!root)
        {
            return;
        }

        if (level_sum.size() < level)
        {
            level_sum.push_back(0);
        }

        level_sum[level - 1] += root->val;

        bfs(root->left, level_sum, level + 1);
        bfs(root->right, level_sum, level + 1);
    }

public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        vector<long long> level_sum;
        bfs(root, level_sum, 1);

        if (level_sum.size() < k)
        {
            return -1;
        }

        sort(level_sum.begin(), level_sum.end(), std::greater());
        return level_sum[k - 1];
    }
};
