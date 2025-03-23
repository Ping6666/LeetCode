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
#include <unordered_map>
using std::vector, std::unordered_map;

// Runtime: 564 ms (Beats 62.06 %), Memory: 479.50 MB (Beats 6.18 %).

// ref. Leetcode Editorial - Approach 4: Eulerian Tour

class Solution
{
private:
    void dfs(TreeNode *root, int height,
             vector<int> &eulerian_idx,
             unordered_map<int, int> &node_height,
             unordered_map<int, int> &first,
             unordered_map<int, int> &last)
    {
        if (!root)
        {
            return;
        }

        node_height[root->val] = height;

        first[root->val] = eulerian_idx.size();
        eulerian_idx.push_back(root->val);

        dfs(root->left, height + 1, eulerian_idx, node_height, first, last);
        dfs(root->right, height + 1, eulerian_idx, node_height, first, last);

        last[root->val] = eulerian_idx.size();
        eulerian_idx.push_back(root->val);
    }

public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        vector<int> eulerian_idx;
        unordered_map<int, int> node_height, first, last;

        dfs(root, 0, eulerian_idx, node_height, first, last);

        int _size = eulerian_idx.size();
        vector<int> max_depth_left(_size), max_depth_right(_size);

        max_depth_left[0] = max_depth_right[_size - 1] = node_height[root->val];

        for (int i = 1; i < _size; i++)
        {
            max_depth_left[i] = max(max_depth_left[i - 1], node_height[eulerian_idx[i]]);
        }
        for (int i = _size - 2; i >= 0; i--)
        {
            max_depth_right[i] = max(max_depth_right[i + 1], node_height[eulerian_idx[i]]);
        }

        int q_len = queries.size();
        vector<int> ans(q_len);

        for (int i = 0; i < q_len; i++)
        {
            int query_val = queries[i];

            int l_max = (first[query_val] > 0) ? max_depth_left[first[query_val] - 1] : 0;
            int r_max = (last[query_val] < _size - 1) ? max_depth_right[last[query_val] + 1] : 0;

            ans[i] = max(l_max, r_max);
        }

        return ans;
    }
};
