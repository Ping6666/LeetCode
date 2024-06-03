#include <iostream>

#include <string>
using std::string;

class Solution
{
    // using magic
    //   Runtime: 16 ms (Beats 99.60 %), Memory: 16.40 MB (Beats 93.55 %).

    // without using magic
    //   Runtime: 34 ms (Beats 75.81 %), Memory: 16.42 MB (Beats 65.32 %).

public:
    bool canMake(char c1, char c2)
    {
        // check if c2 can make from c1

        if (((c1 - 'a') == (c2 - 'a')) || ((((c1 - 'a') + 1) % 26) == (c2 - 'a')))
        {
            return true;
        }

        return false;
    }

    bool canMakeSubsequence(string str1, string str2)
    {
        // magic
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);

        // check if str2 in str1

        int i1 = 0, i2 = 0;

        while (i1 < str1.size() && i2 < str2.size())
        {
            if (canMake(str1[i1], str2[i2]))
            {
                i2++;
            }
            i1++;
        }

        if (i2 == str2.size())
        {
            return true;
        }

        return false;
    }
};
