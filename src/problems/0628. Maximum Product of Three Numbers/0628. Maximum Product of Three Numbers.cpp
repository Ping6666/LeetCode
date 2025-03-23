#include <vector>
using namespace std;

class Solution
{
    // Runtime: 28 ms (98.94 %), Memory: 27.7 MB (78.24 %).
public:
    int maximumProduct(vector<int> &nums)
    {
        int maxNum[3], minNum[2];
        int maxNumLen = 0, minNumLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            /*
            for maxNum
            */
            if (maxNumLen < 3)
            {
                maxNumLen++;
                maxNum[maxNumLen - 1] = nums[i];
            }
            else if (maxNum[maxNumLen - 1] < nums[i])
            {
                maxNum[maxNumLen - 1] = nums[i];
            }
            for (int j = maxNumLen - 2; j >= 0; j--)
            {
                if (maxNum[j] < maxNum[j + 1])
                {
                    int tmpNum = maxNum[j];
                    maxNum[j] = maxNum[j + 1];
                    maxNum[j + 1] = tmpNum;
                }
            }
            /*
            for minNum
            */
            if (minNumLen < 2)
            {
                minNumLen++;
                minNum[minNumLen - 1] = nums[i];
            }
            else if (minNum[minNumLen - 1] > nums[i])
            {
                minNum[minNumLen - 1] = nums[i];
            }
            for (int j = minNumLen - 2; j >= 0; j--)
            {
                if (minNum[j] > minNum[j + 1])
                {
                    int tmpNum = minNum[j];
                    minNum[j] = minNum[j + 1];
                    minNum[j + 1] = tmpNum;
                }
            }
        }
        int maxminindex = 0;
        for (int i = 0; i < maxNumLen - 1; i++)
        {
            if (minNum[0] != maxNum[i] && minNum[1] != maxNum[i])
            {
                break;
            }
            else
            {
                maxminindex++;
            }
        }
        return max(maxNum[0] * maxNum[1] * maxNum[2], minNum[0] * minNum[1] * maxNum[maxminindex]);
    }
};
