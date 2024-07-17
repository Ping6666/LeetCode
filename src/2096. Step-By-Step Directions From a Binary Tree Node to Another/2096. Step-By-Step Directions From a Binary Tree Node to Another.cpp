#include <string>
#include <unordered_map>
#include <vector>
using std::string, std::unordered_map, std::vector, std::pair;

// Runtime: 321 ms (Beats 20.34 %), Memory: 225.10 MB (Beats 7.65 %).
// store the tree in the unordered_map

// it can be done pass the string only

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
    void buidMap(unordered_map<int, pair<int, bool>> &map, TreeNode *root, int p_val, bool is_left)
    {
        if (root == nullptr)
        {
            return;
        }

        map[root->val] = pair<int, bool>(p_val, is_left);

        buidMap(map, root->left, root->val, true);
        buidMap(map, root->right, root->val, false);
        return;
    }

public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        // child map to its parent
        unordered_map<int, pair<int, bool>> map;

        // root parent val set as -1
        buidMap(map, root, -1, false);

        vector<pair<int, bool>> startPath, destPath;

        unordered_map<int, pair<int, bool>>::iterator it;

        while (startValue != -1)
        {
            it = map.find(startValue);
            startPath.push_back(it->second);
            startValue = it->second.first;
        }
        while (destValue != -1)
        {
            it = map.find(destValue);
            destPath.push_back(it->second);
            destValue = it->second.first;
        }

        int startIdx = startPath.size() - 1, destIdx = destPath.size() - 1;

        while (startIdx >= 0 && destIdx >= 0)
        {
            if ((startPath[startIdx].first == destPath[destIdx].first) &&
                (startPath[startIdx].second == destPath[destIdx].second))
            {
                startIdx--;
                destIdx--;
            }
            else
            {
                break;
            }
        }

        // printf("%d %d\n", startIdx, destIdx);

        string s;

        for (int i = 0; i <= startIdx; i++)
        {
            s += 'U';
        }
        for (int i = destIdx; i >= 0; i--)
        {
            if (destPath[i].second)
            {
                // is left
                s += 'L';
            }
            else
            {
                s += 'R';
            }
        }

        return s;
    }
};
