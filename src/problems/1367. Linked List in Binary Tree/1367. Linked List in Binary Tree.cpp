// with queue
//   Runtime: 28 ms (Beats 34.10 %), Memory: 31.03 MB (Beats 15.79 %).

// with dfs
//   Runtime: 19 ms (Beats 90.39 %), Memory: 30.64 MB (Beats 87.87 %).

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool isSubNode(ListNode *head, TreeNode *root)
    {
        if (!head)
        {
            return true;
        }
        else if (!root)
        {
            return false;
        }

        if (head->val != root->val)
        {
            return false;
        }

        return isSubNode(head->next, root->left) || isSubNode(head->next, root->right);
    }

    bool dfs(ListNode *head, TreeNode *root)
    {
        if (!root)
        {
            return false;
        }
        if (isSubNode(head, root))
        {
            return true;
        }

        return dfs(head, root->left) || dfs(head, root->right);
    }

public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        return dfs(head, root);
    }
};
