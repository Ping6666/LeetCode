#include <vector>
using namespace std;

class Solution
{
    // Runtime: 8 ms (98.68 %), Memory: 16.4 MB (42.54 %).
public:
    int jump(vector<int> &nums)
    {
        int currentMaxJump = 0, allMaxJump = 0;
        int ansJump = 0;
        // want check last element
        for (int i = 0; i < nums.size() - 1; i++)
        {
            allMaxJump = max(allMaxJump, i + nums[i]);
            if (i == currentMaxJump)
            {
                ansJump++;
                currentMaxJump = allMaxJump;
            }
        }
        return ansJump;
    }
};

/*
class Solution
{
    // Runtime: 412 ms (21.43 %), Memory: 17.2 MB (13.03 %).
public:
    int jump(vector<int> &nums)
    {
        int vlen = nums.size();
        vector<int> dpJumpTable(vlen, -1);
        dpJumpTable[0] = 0;
        for (int i = 0; i < vlen; i++)
        {
            if (dpJumpTable[vlen - 1] != -1)
                break;
            for (int j = 1; j <= nums[i] && i + j < vlen; j++)
            {
                if (dpJumpTable[i + j] == -1)
                    dpJumpTable[i + j] = dpJumpTable[i] + 1;
                else
                    dpJumpTable[i + j] = min(dpJumpTable[i] + 1, dpJumpTable[i + j]);
            }
        }
        return dpJumpTable[vlen - 1];
    }
};
*/
