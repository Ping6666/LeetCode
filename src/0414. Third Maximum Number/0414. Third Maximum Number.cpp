#include <vector>
using namespace std;

class Solution
{
    // Runtime: 0 ms (100.00 %), Memory: 9 MB (94.21 %).
public:
    int thirdMax(vector<int> &nums)
    {
        int maxNum[3];
        int maxNumLen = 0; // len of maxNum[3]
        for (int i = 0; i < nums.size(); i++)
        {
            bool addCheck = true;
            for (int j = 0; j < maxNumLen && addCheck; j++)
            {
                if (maxNum[j] == nums[i])
                {
                    addCheck = false;
                }
            }
            if (addCheck)
            {
                if (maxNumLen < 3)
                {
                    maxNumLen++;
                    maxNum[maxNumLen - 1] = nums[i];
                }
                else if (maxNum[maxNumLen - 1] < nums[i])
                {
                    maxNum[maxNumLen - 1] = nums[i];
                }
            }
            for (int j = 0; j < maxNumLen - 1 && j < 2; j++)
            {
                if (maxNum[j] < maxNum[j + 1])
                {
                    int tmpNum = maxNum[j];
                    maxNum[j] = maxNum[j + 1];
                    maxNum[j + 1] = tmpNum;
                }
            }
        }
        if (maxNumLen < 3)
            return maxNum[0];
        return maxNum[2];
    }
};
