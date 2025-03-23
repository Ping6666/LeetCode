#include <vector>
using std::vector;

// Runtime: 36 ms (Beats 93.17 %), Memory: 33.42 MB (Beats 66.83 %).

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
    vector<int> parser(TreeNode *root, const int &distance, int &counter)
    {
        if (root == nullptr)
        {
            return {};
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return {1};
        }

        vector<int> l = parser(root->left, distance, counter);
        vector<int> r = parser(root->right, distance, counter);

        for (const int &ll : l)
        {
            for (const int &rr : r)
            {
                if (ll > 0 && rr > 0)
                {
                    if (ll + rr <= distance)
                    {
                        counter++;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i : l)
        {
            if (i > 0 && i < distance)
            {
                ans.push_back(i + 1);
            }
        }
        for (int i : r)
        {
            if (i > 0 && i < distance)
            {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }

public:
    int countPairs(TreeNode *root, int distance)
    {
        int counter = 0;
        parser(root, distance, counter);

        return counter;
    }
};
