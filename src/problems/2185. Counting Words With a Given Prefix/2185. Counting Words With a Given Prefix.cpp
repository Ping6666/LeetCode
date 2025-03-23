#include <string>
#include <vector>
using std::string, std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 12.92 MB (Beats 95.47 %).

class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int ans = 0;

        int pref_len = pref.size();
        for (const auto &w : words)
        {
            int w_len = w.size();
            if (w_len < pref_len)
            {
                continue;
            }

            bool check = true;
            for (int i = 0; i < pref_len && check; i++)
            {
                if (pref[i] != w[i])
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                ans++;
            }
        }
        return ans;
    }
};
