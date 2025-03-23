#include <string>
#include <map>
using std::string, std::map, std::pair;

// Runtime: 2 ms (Beats 97.47 %), Memory: 10.61 MB (Beats 85.61 %).

class Solution
{
public:
    int maximumLength(string s)
    {
        map<pair<char, int>, int> char_len_count;

        int n = s.size();

        char c = ' ';
        int sub_len = 0;

        for (int i = 0; i < n; i++)
        {
            c = s[i];
            sub_len = 0;

            for (int j = i; j < n; j++)
            {
                // special substring
                if (c == s[j])
                {
                    sub_len++;

                    char_len_count[{c, sub_len}]++;
                }
                else
                {
                    break;
                }
            }
        }

        int ans = 0;
        for (const auto &clc : char_len_count)
        {
            if (clc.second >= 3 && clc.first.second > ans)
            {
                ans = clc.first.second;
            }
        }

        if (ans == 0)
        {
            return -1;
        }

        return ans;
    }
};
