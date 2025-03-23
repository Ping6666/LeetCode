#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using std::vector, std::unordered_map, std::unordered_set;

// Runtime: 659 ms (Beats 83.84 %), Memory: 292.73 MB (Beats 33.63 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> table;
        unordered_set<int> parents, children;
        TreeNode *p, *c;

        unordered_map<int, TreeNode *>::iterator it;

        for (const auto &desc : descriptions)
        {
            parents.insert(desc[0]);
            children.insert(desc[1]);

            it = table.find(desc[0]);
            if (it != table.end())
            {
                p = it->second;
            }
            else
            {
                p = new TreeNode(desc[0]);
                table[desc[0]] = p;
            }

            it = table.find(desc[1]);
            if (it != table.end())
            {
                c = it->second;
            }
            else
            {
                c = new TreeNode(desc[1]);
                table[desc[1]] = c;
            }

            if (desc[2] == 1)
            {
                // left
                p->left = c;
            }
            else
            {
                p->right = c;
            }
        }

        for (const auto &c : children)
        {
            parents.erase(c);
        }

        return table[*parents.begin()];
    }
};
