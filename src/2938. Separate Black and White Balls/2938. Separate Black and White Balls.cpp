#include <string>
using std::string;

// Runtime: 26 ms (Beats 90.53 %), Memory: 15.46 MB (Beats 89.89 %).

// First try XD
// Two Pointers + Greedy

class Solution
{
public:
    long long minimumSteps(string s)
    {
        // 000...111

        long long ans = 0;

        int n = s.size();
        int l_one = 0, r_one = 0;

        while (r_one < n && s[r_one] != '1')
        {
            r_one++;
        }

        l_one = r_one++;

        while (r_one < n && s[r_one] != '0')
        {
            r_one++;
        }

        while (r_one < n)
        {
            ans += (r_one - l_one);
            r_one++;
            l_one++;

            while (r_one < n && s[r_one] != '0')
            {
                r_one++;
            }
        }

        return ans;
    }
};
