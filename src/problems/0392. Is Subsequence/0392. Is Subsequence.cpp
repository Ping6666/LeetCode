#include <string>
using std::string;

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 7.34 MB (Beats 93.62 %).
    // also see q.0792, q.2486

public:
    bool isSubsequence(string s, string t)
    {
        int i = -1;

        for (auto ss : s)
        {
            i = t.find(ss, i + 1);

            if (i == -1)
            {
                return false;
            }
        }

        return true;
    }
};

/*
class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 7.43 MB (Beats 69.07 %).
    // also see q.0792, q.2486

public:
    bool isSubsequence(string s, string t)
    {
        if (s.size() == 0 && t.size() == 0)
        {
            return true;
        }

        int s_idx = 0;
        int s_len = s.size();

        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] == s[s_idx])
            {
                s_idx++;
            }

            if (s_idx >= s_len)
            {
                return true;
            }
        }

        return false;
    }
};
*/
