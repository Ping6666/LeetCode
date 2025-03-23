#include <vector>
#include <unordered_map>
#include <algorithm>
using std::vector, std::unordered_map, std::sort, std::swap;

// Runtime: 127 ms (Beats 52.78 %), Memory: 203.29 MB (Beats 40.47 %).

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
    void bfs(TreeNode *_curr, vector<vector<int>> &level_group, int level)
    {
        if (!_curr)
        {
            return;
        }

        if (level_group.size() < level + 1)
        {
            level_group.push_back({});
        }
        level_group[level].push_back(_curr->val);

        bfs(_curr->left, level_group, level + 1);
        bfs(_curr->right, level_group, level + 1);
    }

public:
    int minimumOperations(TreeNode *root)
    {
        vector<vector<int>> level_group;
        bfs(root, level_group, 0);

        int ans = 0;

        int n;
        unordered_map<int, int> m;

        for (auto &ori : level_group)
        {
            n = ori.size();
            if (n <= 1)
            {
                continue;
            }

            vector<int> tgt = ori;

            m.clear();
            for (int i = 0; i < n; i++)
            {
                m[ori[i]] = i;
            }

            sort(tgt.begin(), tgt.end());

            for (int i = 0; i < n; i++)
            {
                if (ori[i] != tgt[i])
                {
                    m[ori[i]] = m[tgt[i]];
                    swap(ori[m[tgt[i]]], ori[i]);
                    // m[tgt[i]] = i;

                    ans++;
                }
            }

            // for (const auto &g : group)
            // {
            //     printf("%d ", g->val);
            // }
            // printf("\n");
        }
        return ans;
    }
};
