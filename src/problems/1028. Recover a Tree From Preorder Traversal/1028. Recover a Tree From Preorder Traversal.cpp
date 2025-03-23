#include <string>
#include <stack>
using std::string, std::stack;

// Runtime: 8 ms (Beats 22.54 %), Memory: 20.72 MB (Beats 85.56 %).

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
    int numOfDashes(const string &s, const int start)
    {
        int n = s.size(), i = 0;
        while (i + start < n)
        {
            if (s[i + start] != '-')
            {
                return i;
            }
            i++;
        }
        return i;
    }

    int getNum(const string &s, const int start, int &num)
    {
        num = 0;

        int n = s.size(), i = 0;
        while (i + start < n)
        {
            if ('0' <= s[i + start] && s[i + start] <= '9')
            {
                num *= 10;
                num += s[i + start] - '0';
            }
            else
            {
                return i;
            }

            i++;
        }
        return i;
    }

public:
    TreeNode *recoverFromPreorder(string traversal)
    {
        int i = 0, d, l;
        int num = 0;

        l = getNum(traversal, i, num);
        i += l;

        TreeNode *root = new TreeNode(num);

        stack<TreeNode *> _stack;
        _stack.push(root);

        int n = traversal.size();
        while (i < n)
        {
            num = 0;
            d = numOfDashes(traversal, i);
            l = getNum(traversal, i + d, num);

            printf("%d %d %d\n", i, d, num);

            i += d + l;

            while (!_stack.empty() && d < _stack.size())
            {
                _stack.pop();
            }

            auto t = _stack.top();
            TreeNode *_next = new TreeNode(num);
            _stack.push(_next);

            if (!t->left)
            {
                // fill left
                t->left = _next;
            }
            else
            {
                // fill right
                t->right = _next;
            }
        }

        return root;
    }
};
