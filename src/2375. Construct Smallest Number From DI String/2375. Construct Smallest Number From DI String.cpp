#include <string>
#include <algorithm>
using std::string, std::reverse;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.69 MB (Beats 94.52 %).

class Solution
{
public:
    string smallestNumber(string pattern)
    {
        int n = pattern.size();
        string ans = "";
        for (int i = 1; i <= n + 1; i++)
        {
            ans += '0' + i;
        }

        int d_len = 0;
        for (int i = 0; i < n; i++)
        {
            if (pattern[i] != 'D')
            {
                if (d_len != 0)
                {
                    // reverse
                    // range: [i - d_len, i]
                    reverse(ans.begin() + i - d_len, ans.begin() + i + 1);

                    // reset
                    d_len = 0;
                }
            }
            else
            {
                d_len++;
            }
        }

        if (d_len != 0)
        {
            // reverse
            // range: [i - d_len, i]
            reverse(ans.begin() + n - d_len, ans.begin() + n + 1);

            // reset
            d_len = 0;
        }

        return ans;
    }
};
