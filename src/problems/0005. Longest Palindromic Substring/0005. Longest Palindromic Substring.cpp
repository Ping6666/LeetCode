#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    // Manacher's algorithm

    // Time complexity: O( n )
    // Runtime: 0 ms (100.00 %), Memory: 8.4 MB (63.30 %).

public:
    string longestPalindrome(string s)
    {
        char bogus = '*'; // can be any character without the consist of the characters
        int sLen = 2 * s.length() + 1;
        vector<int> dpTable(sLen);
        string tmpStr;
        tmpStr.reserve(sLen);
        tmpStr = bogus;
        for (int i = 0; i < s.length(); i++)
        {
            tmpStr += s[i];
            tmpStr += bogus;
        }
        dpTable[0] = 0;
        int anchor = 0, tRange = 0, tStart = 0;
        for (int i = 1; i < sLen; i++)
        {
            int checkR = -1;
            int currentR = anchor + dpTable[anchor];
            int targetI = anchor - (i - anchor);
            if (i > currentR)
            {
                // check from self
                checkR = 1;
            }
            else if (i + dpTable[targetI] == currentR)
            {
                // only check outside the range
                checkR = dpTable[targetI];
            }
            if (checkR == -1)
            {
                dpTable[i] = min(currentR - i, dpTable[targetI]);
            }
            else
            {
                while (i - checkR >= 0 && i + checkR < sLen && tmpStr[i - checkR] == tmpStr[i + checkR])
                {
                    checkR++;
                }
                dpTable[i] = checkR - 1;
                anchor = i;
                if (dpTable[i] > tRange)
                {
                    tRange = dpTable[i];
                    tStart = i - tRange;
                }
            }
        }
        return s.substr(tStart / 2, tRange);
    }
};

/*
class Solution
{
    // Runtime: 20 ms (83.90 %), Memory: 10.7 MB (60.68 %).
public:
    string longestPalindrome(string s)
    {
        string ansStr;
        int slen = s.length();
        for (int mid = 0; mid < slen; mid++)
        {
            int tStart = mid, tLen = 1;
            int iLeft = mid - 1, iRight = mid + 1;
            while (iLeft >= 0 && iRight < slen)
            {
                if (s[iLeft] == s[iRight])
                {
                    tStart = iLeft;
                    tLen = iRight - iLeft + 1;
                    iLeft--;
                    iRight++;
                }
                else
                {
                    break;
                }
            }
            iLeft = mid, iRight = mid + 1;
            while (iLeft >= 0 && iRight < slen)
            {
                if (s[iLeft] == s[iRight])
                {
                    if (iRight - iLeft + 1 > tLen)
                    {
                        tStart = iLeft;
                        tLen = iRight - iLeft + 1;
                    }
                    iLeft--;
                    iRight++;
                }
                else
                {
                    break;
                }
            }
            if (tLen > 0 && tLen > ansStr.length())
                ansStr = s.substr(tStart, tLen);
        }
        return ansStr;
    }
};
*/
