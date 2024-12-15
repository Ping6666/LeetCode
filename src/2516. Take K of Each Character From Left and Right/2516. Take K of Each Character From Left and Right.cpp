#include <string>
using std::string, std::max;

// Runtime: 2 ms (Beats 98.54 %), Memory: 11.84 MB (Beats 96.89 %).

class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        int a = -k, b = -k, c = -k;
        for (const char &ch : s)
        {
            if (ch == 'a')
            {
                a++;
            }
            else if (ch == 'b')
            {
                b++;
            }
            else
            {
                c++;
            }
        }

        if (a < 0 || b < 0 || c < 0)
        {
            return -1;
        }

        int n = s.size(), l = 0, r = 0;
        int _a = 0, _b = 0, _c = 0;
        int ans = 0;

        while (r < n)
        {
            if (s[r] == 'a')
            {
                _a++;
            }
            else if (s[r] == 'b')
            {
                _b++;
            }
            else
            {
                _c++;
            }

            while (l <= n && (_a > a || _b > b || _c > c))
            {
                if (s[l] == 'a')
                {
                    _a--;
                }
                else if (s[l] == 'b')
                {
                    _b--;
                }
                else
                {
                    _c--;
                }
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return n - ans;
    }
};
