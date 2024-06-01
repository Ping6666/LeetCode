#include <vector>
using namespace std;

class Solution
{
    // Runtime: 52 ms (93.23 %), Memory: 48.2 MB (79.20 %).
public:
    bool canJump(vector<int> &nums)
    {
        int maxJump = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > maxJump)
            {
                return false;
            }
            else if (maxJump >= nums.size() - 1)
            {
                return true;
            }
            maxJump = max(maxJump, i + nums[i]);
        }
        return true;
    }
};
