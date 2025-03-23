#include <string>
using namespace std;

class Solution
{
    // Runtime: 3 ms (94.34 %), Memory: 5.8 MB (98.03 %).
public:
    int romanToInt(string s)
    {
        int ans = 0, len = s.length();
        bool nextChar;
        for (int i = 0; i < len; i++)
        {
            nextChar = false;
            if (i < len - 1)
                nextChar = true;
            switch (s[i])
            {
            case 'I':
                if (nextChar)
                {
                    switch (s[i + 1])
                    {
                    case 'V':
                        ans += 4; // 5 - 1
                        i++;
                        break;
                    case 'X':
                        ans += 9; // 10 - 1
                        i++;
                        break;
                    default:
                        ans += 1;
                        break;
                    }
                }
                else
                {
                    ans += 1;
                }
                break;
            case 'V':
                ans += 5;
                break;
            case 'X':
                if (nextChar)
                {
                    switch (s[i + 1])
                    {
                    case 'L':
                        ans += 40; // 50 - 10
                        i++;
                        break;
                    case 'C':
                        ans += 90; // 100 - 10
                        i++;
                        break;
                    default:
                        ans += 10;
                        break;
                    }
                }
                else
                {
                    ans += 10;
                }
                break;
            case 'L':
                ans += 50;
                break;
            case 'C':
                if (nextChar)
                {
                    switch (s[i + 1])
                    {
                    case 'D':
                        ans += 400; // 500 - 100
                        i++;
                        break;
                    case 'M':
                        ans += 900; // 1000 - 100
                        i++;
                        break;
                    default:
                        ans += 100;
                        break;
                    }
                }
                else
                {
                    ans += 100;
                }
                break;
            case 'D':
                ans += 500;
                break;
            case 'M':
                ans += 1000;
                break;
            default:
                break;
            }
        }
        return ans;
    }
};
