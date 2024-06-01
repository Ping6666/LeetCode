#include <vector>
using namespace std;

class Solution
{
    // Runtime: 36 ms (72.07 %), Memory: 36.1 MB (95.97 %).
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int curCal = 0, maxCal = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                curCal = 0;
            }
            curCal += nums[i];
            if (maxCal < curCal)
            {
                maxCal = curCal;
            }
        }
        return maxCal;
    }
};
