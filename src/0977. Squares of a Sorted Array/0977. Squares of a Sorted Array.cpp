#include <math.h>
#include <vector>
using namespace std;

class Solution
{
    // Runtime: 16 ms (99.78 %), Memory: 25.7 MB (99.85 %).
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int vCounter = nums.size();
        vector<int> ansVector(vCounter);
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            vCounter--;
            if (abs(nums[i]) < abs(nums[j]))
            {
                ansVector[vCounter] = nums[j] * nums[j];
                j--;
            }
            else
            {
                ansVector[vCounter] = nums[i] * nums[i];
                i++;
            }
        }
        return ansVector;
    }
};
