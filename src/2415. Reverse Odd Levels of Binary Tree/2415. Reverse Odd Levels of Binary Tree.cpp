#include <queue>
using std::queue, std::deque;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Runtime: 0 ms (Beats 100.00 %), Memory: 77.02 MB (Beats 74.77 %).
// Time: O(n); Space: O(log(n))

class Solution
{
private:
    void dfs(TreeNode *l, TreeNode *r, const int level)
    {
        if (!l || !r)
        {
            return;
        }

        if (level % 2 == 1)
        {
            int t = l->val;
            l->val = r->val;
            r->val = t;
        }

        dfs(l->left, r->right, level + 1);
        dfs(l->right, r->left, level + 1);
    }

public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        dfs(root->left, root->right, 1);
        return root;
    }
};

// Runtime: 3 ms (Beats 50.72 %), Memory: 83.26 MB (Beats 21.98 %).
// Time: O(2*n); Space: O(n)

/*
class Solution
{

public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        deque<TreeNode *> dq;

        int level = 0;
        int temp;

        q.push(root);
        while (true)
        {
            dq.clear();

            for (int i = 0; i < (1 << level); i++)
            {
                auto f = q.front();
                q.pop();

                if (!f)
                {
                    return root;
                }

                if (level % 2 == 1)
                {
                    // odd level
                    dq.push_back(f);
                }

                q.push(f->left);
                q.push(f->right);
            }
            level++;

            while (!dq.empty())
            {
                auto f = dq.front();
                dq.pop_front();

                auto b = dq.back();
                dq.pop_back();

                temp = f->val;
                f->val = b->val;
                b->val = temp;
            }
        }

        return root;
    }
};
*/
