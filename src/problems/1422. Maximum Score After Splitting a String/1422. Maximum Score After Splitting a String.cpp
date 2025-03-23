#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 8.62 MB (Beats 52.60 %).

class Solution
{
public:
    int maxScore(string s)
    {
        int n = s.size();

        int zeros = 0, ones = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                ones++;
            }
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '0')
            {
                zeros++;
            }
            else
            {
                ones--;
            }

            ans = max(ans, zeros + ones);
        }
        return ans;
    }
};
