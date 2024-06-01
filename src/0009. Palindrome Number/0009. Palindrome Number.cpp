class Solution
{
    // Runtime: 0 ms (100.00 %), Memory: 5.6 MB (100.00 %).
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        else if (x < 10)
            return true;
        int checker = 0, orgNum = x;
        while (x > 0)
        {
            if (checker >= 214748365)
                return false; // prevent signed integer overflow
            checker *= 10;
            checker += x % 10;
            x /= 10;
        }
        return orgNum == checker;
    }
};

/*
#include <cstdio>

class Solution
{
    // Runtime: 7 ms (84.34 %), Memory: 5.8 MB (73.81 %).
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        else if (x < 10)
            return true;
        char intToChar[12] = {0};
        int len = sprintf(intToChar, "%d", x);
        for (int i = 0; i < len / 2; i++)
        {
            if (intToChar[i] != intToChar[len - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};
*/
