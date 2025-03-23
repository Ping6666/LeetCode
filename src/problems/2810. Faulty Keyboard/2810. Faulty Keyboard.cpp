#include <string>
#include <algorithm>
using std::string, std::reverse;

class Solution
{
    // Runtime: 3 ms (Beats 87.24 %), Memory: 9.16 MB (Beats 99.05 %).
    // in-place

public:
    string finalString(string s)
    {
        int l = s.size();
        for (int i = 0; i < l; i++)
        {
            if (s[i] == 'i')
            {
                // do rev. and remove 'i'
                if (i > 1)
                {
                    reverse(s.begin(), s.begin() + i);
                }

                s.erase(s.begin() + i);
                i--;
                l--;
            }
        }

        return s;
    }
};
