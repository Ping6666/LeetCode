#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class Solution
{
    // Runtime: 0 ms (100.00 %), Memory: 5.8 MB (96.23 %).
public:
    int divide(int dividend, int divisor)
    {
        /*
        *** Restriction ***
        1. divide two integers without using multiplication, division, and mod operator
        2. only store integers within the 32-bit signed integer range
        */
        if (!dividend)
            return 0;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        else if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        else if (dividend == INT_MIN && divisor == INT_MIN)
            return 1;
        else if (dividend != INT_MIN && divisor == INT_MIN)
            return 0;
        bool posCheck = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0));
        bool setter = false;
        if (dividend == INT_MIN)
        {
            setter = true;
            dividend = INT_MAX;
        }
        dividend = abs(dividend);
        divisor = abs(divisor);
        int ans = 0, shifter = 31; // 32-bit signed integer range
        while (divisor >> (31 - shifter) > 0)
            shifter--;
        while (dividend > 0 && shifter >= 0)
        {
            if (divisor << shifter <= dividend)
            {
                // divisor * (2 ^ i) <= dividend.
                dividend -= divisor << shifter;
                ans += 1 << shifter;
                if (setter) // just for INT_MIN first time run
                {
                    setter = false;
                    dividend += 1;
                    shifter++; // redo
                }
            }
            shifter--;
        }
        return posCheck ? ans : ans * -1;
    }
};
