#include <string>
#include <vector>
#include <algorithm>
using std::string, std::vector, std::reverse;

class Solution
{
    // Runtime: 10 ms (Beats 98.75 %), Memory: 14.90 MB (Beats 79.30 %).

public:
    string largestPalindromic(string num)
    {
        vector<int> table(10, 0);

        for (auto n : num)
        {
            table[n - '0']++;
        }

        string s;
        char mid = ' ';
        for (int i = 9; i >= 0; i--)
        {
            if (i != 0)
            {
                // ref. https://stackoverflow.com/a/166646
                s += std::string(table[i] / 2, ('0' + i));
            }
            else if (s.size() > 0)
            {
                // ref. https://stackoverflow.com/a/166646
                s += std::string(table[i] / 2, '0');
            }

            if (mid == ' ' && table[i] % 2 == 1)
            {
                mid = ('0' + i);
            }
        }

        string ss = s;
        reverse(ss.begin(), ss.end());

        if (mid != ' ')
        {
            s += mid;
        }
        s += ss;

        if (s.size() == 0 && table[0] > 0)
        {
            // all zero need to return "0"
            s = "0";
        }

        return s;
    }
};
