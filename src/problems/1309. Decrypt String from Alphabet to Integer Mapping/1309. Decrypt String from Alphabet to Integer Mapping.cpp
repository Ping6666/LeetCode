#include <string>
#include <algorithm>
using std::string, std::reverse;

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 7.27 MB (Beats 93.22 %).

public:
    char chars_2_char(char a, char b)
    {
        return 'j' + ((a - '1') * 10 + b - '0');
    }

    char char_2_char(char a)
    {
        return 'a' + (a - '1');
    }

    string freqAlphabets(string s)
    {
        string ss = "";
        int i = s.size() - 1;

        while (i >= 0)
        {
            if (s[i] == '#')
            {
                ss += chars_2_char(s[i - 2], s[i - 1]);
                i -= 3;
            }
            else
            {
                ss += char_2_char(s[i]);
                i--;
            }
        }

        reverse(ss.begin(), ss.end());

        return ss;
    }
};
