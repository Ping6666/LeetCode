#include <stdio.h>

#include <vector>
#include <map>           // map
#include <unordered_map> // unordered_map

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    // Runtime: 93 ms (Beats 91.14 %), Memory: 28.7 MB (Beats 58.40 %).

private:
    // map<int, vector<TreeNode *>> vec_map;
    unordered_map<int, vector<TreeNode *>> vec_map;

public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        // in order to meet the problem requirement
        // need to guarantee that the n is odd number

        vector<TreeNode *> roots;

        if (n == 1)
        {
            roots = vector<TreeNode *>(1, new TreeNode(0));
        }
        else if (n == 3)
        {
            TreeNode *left_node = new TreeNode(0);
            TreeNode *right_node = new TreeNode(0);

            roots = vector<TreeNode *>(1, new TreeNode(0, left_node, right_node));
        }
        else
        {
            vector<TreeNode *> left_node, right_node;

            for (int i = 1; i < n; i += 2)
            {
                if (vec_map.find(i) == vec_map.end())
                {
                    left_node = allPossibleFBT(i);
                    vec_map[i] = left_node;
                }
                else
                {
                    left_node = vec_map[i];
                }

                if (vec_map.find(n - 1 - i) == vec_map.end())
                {
                    right_node = allPossibleFBT(n - 1 - i);
                    vec_map[n - 1 - i] = right_node;
                }
                else
                {
                    right_node = vec_map[n - 1 - i];
                }

                for (int i = 0; i < left_node.size(); i++)
                {
                    for (int j = 0; j < right_node.size(); j++)
                    {
                        roots.push_back(new TreeNode(0, left_node[i], right_node[j]));
                    }
                }
            }
        }

        return roots;
    }
};

int main()
{
    Solution s;

    s = Solution();
    s.allPossibleFBT(7);

    s = Solution();
    s.allPossibleFBT(3);

    return 0;
}
