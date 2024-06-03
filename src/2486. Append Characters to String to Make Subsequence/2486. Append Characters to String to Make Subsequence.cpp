#include <string>
using std::string;

class Solution
{
    // Runtime: 16 ms (Beats 74.78 %), Memory: 11.82 MB (Beats 83.42 %).

public:
    int appendCharacters(string s, string t)
    {
        int t_idx = 0;
        int t_len = t.size();

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == t[t_idx])
            {
                t_idx++;
            }

            if (t_idx >= t_len)
            {
                return 0;
            }
        }

        return t_len - t_idx;
    }
};
