class Solution
{
    // Runtime: 0 ms (100.00 %), Memory: 5.7 MB (97.24 %).
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        int ansNum = 1, tmpNum = 1;
        n -= 2;
        while (n >= 0)
        {
            ansNum += tmpNum;
            tmpNum = ansNum - tmpNum;
            n--;
        }
        return ansNum;
    }
};

/*
#include <vector>
using namespace std;

class Solution
{
    // Runtime: 0 ms (100.00 %), Memory: 6.1 MB (28.27 %).
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        vector<int> ansTable(n);
        ansTable[0] = 1, ansTable[1] = 2;
        // Stair: n = 1, 1; n = 2, 2.
        for (int i = 2; i < n; i++)
        {
            ansTable[i] = ansTable[i - 2] + ansTable[i - 1];
        }
        return ansTable[n - 1];
    }
};
*/
