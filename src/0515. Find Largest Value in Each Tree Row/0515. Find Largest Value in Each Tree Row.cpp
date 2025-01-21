#include <limits.h>
#include <vector>
#include <queue>
using std::vector, std::queue, std::max;

// Runtime: 0 ms (Beats 100.00 %), Memory: 22.90 MB (Beats 15.81 %).

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
    vector<int> largestValues(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        vector<int> ans;

        int n;
        while (!q.empty())
        {
            n = q.size();

            bool got_num = false;
            int _ans = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                auto f = q.front();
                q.pop();

                if (!f)
                {
                    continue;
                }

                got_num = true;
                _ans = max(_ans, f->val);

                q.push(f->left);
                q.push(f->right);
            }

            if (got_num)
            {
                ans.push_back(_ans);
            }
        }

        return ans;
    }
};
