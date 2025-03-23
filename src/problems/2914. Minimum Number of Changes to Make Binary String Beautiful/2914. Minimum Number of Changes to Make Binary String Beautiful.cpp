#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 12.16 MB (Beats 67.52 %).

class Solution
{
public:
    int minChanges(string s)
    {
        int ans = 0;

        for (int i = 0; i < s.size(); i += 2)
        {
            if (s[i] != s[i + 1])
            {
                ans++;
            }
        }

        return ans;
    }
};
