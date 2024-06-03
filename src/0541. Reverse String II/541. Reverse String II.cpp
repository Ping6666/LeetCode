#include <string>
#include <algorithm>
using std::string, std::reverse;

class Solution
{
    // Runtime: 3 ms (Beats 87.09 %), Memory: 8.38 MB (Beats 95.11 %).
    // in-place

public:
    string reverseStr(string s, int k)
    {
        const int l = s.size();

        for (int i = 0; i < l; i += 2 * k)
        {
            if (i + k > l)
            {
                reverse(s.begin() + i, s.end());
            }
            else
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
        }

        return s;
    }
};

/*
class Solution
{
    // Runtime: 2 ms (Beats 88.53 %), Memory: 9.52 MB (Beats 6.53 %).

public:
    string reverseStr(string s, int k)
    {
        const int l = s.size();
        string rev_s = "";

        bool flip = true;
        for (int i = 0; i < l; i += k)
        {
            int ll = k;
            if (i + k > l)
            {
                ll = l - i;
            }

            rev_s += s.substr(i, ll);
            if (flip)
            {
                reverse(rev_s.begin() + i, rev_s.end());
            }
            flip = !flip;
        }

        return rev_s;
    }
};
*/
