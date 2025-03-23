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
#include <queue>
using std::vector, std::priority_queue, std::pair;

// Runtime: 88 ms (Beats 94.43 %), Memory: 315.02 MB (Beats 26.73 %).
// see 2583

class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        priority_queue<pair<int, TreeNode *>, vector<pair<int, TreeNode *>>, std::greater<pair<int, TreeNode *>>> table;

        root->val = 0;
        table.emplace(0, root);

        vector<TreeNode *> cousins;

        int c_level = 0, c_sum = 0, s_sum = 0;

        while (!table.empty())
        {
            auto t = table.top();
            table.pop();

            if (!t.second)
            {
                continue;
            }

            // printf("%d %d\n", t.first, t.second->val);

            if (t.first != c_level)
            {
                for (const auto &c : cousins)
                {
                    s_sum = 0;
                    if (c->left)
                    {
                        s_sum += c->left->val;
                    }
                    if (c->right)
                    {
                        s_sum += c->right->val;
                    }

                    if (c->left)
                    {
                        c->left->val = c_sum - s_sum;
                    }
                    if (c->right)
                    {
                        c->right->val = c_sum - s_sum;
                    }
                }

                c_level = t.first;
                c_sum = 0;
                cousins.clear();
            }

            if (t.second->left)
            {
                c_sum += t.second->left->val;
            }
            if (t.second->right)
            {
                c_sum += t.second->right->val;
            }

            cousins.push_back(t.second);

            table.emplace(t.first + 1, t.second->left);
            table.emplace(t.first + 1, t.second->right);
        }

        return root;
    }
};
