#include <unordered_set>
using std::unordered_set;

// Runtime: 7 ms (Beats 82.43 %), Memory: 34.50 MB (Beats 67.66 %).

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements
{
private:
    unordered_set<int> s;

    void fillOut(TreeNode *root, int val)
    {
        if (!root)
        {
            return;
        }

        s.insert(val);

        fillOut(root->left, 2 * val + 1);
        fillOut(root->right, 2 * val + 2);
    }

public:
    FindElements(TreeNode *root)
    {
        fillOut(root, 0);
    }

    bool find(int target)
    {
        return s.count(target) != 0;
        // return s.find(target) != s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
