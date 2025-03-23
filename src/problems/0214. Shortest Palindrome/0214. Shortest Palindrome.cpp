#include <string>
#include <vector>
using std::string, std::vector;

// Runtime: 195 ms (Beats 5.09 %), Memory: 9.35 MB (Beats 98.32 %).

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        int n = s.size();

        if (n <= 1)
        {
            return s;
        }

        int i, j;
        bool good = false, check;

        for (i = n * 2 - (n - 1) - 1; i >= 2 && !good; i--)
        {
            if (!(i % 2))
            {
                // even
                j = i / 2, check = true;
                for (int k = j - 1; k >= 0 && check; k--)
                {
                    // k + (j - k - 1) * 2 + 1
                    if (s[k] != s[2 * j - k - 1])
                    {
                        check = false;
                        break;
                    }
                }

                if (check)
                {
                    good = true;
                    break;
                }
            }
            else
            {
                // odd
                j = i / 2, check = true;
                for (int k = j - 1; k >= 0 && check; k--)
                {
                    // k + (j - k) * 2
                    if (s[k] != s[2 * j - k])
                    {
                        check = false;
                        break;
                    }
                }

                if (check)
                {
                    good = true;
                    break;
                }
            }
        }

        if (!good)
        {
            i = 1;
        }

        string front_s = "";
        for (int j = n - 1; j >= i; j--)
        {
            front_s += s[j];
        }

        return front_s + s;
    }
};
