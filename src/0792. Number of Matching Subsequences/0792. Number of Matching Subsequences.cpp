#include <iostream>

#include <string>
#include <vector>
using std::string, std::vector;

class Solution
{
    // pass by reference
    //   bool solve(string &s, string &t)
    //   Runtime: 85 ms (Beats 99.90 %), Memory: 38.12 MB (Beats 98.55 %).

    // pass by value
    //   bool solve(string s, string t)
    //   Runtime: 429 ms (Beats 26.96 %), Memory: 332.94 MB (Beats 22.61 %).

public:
    bool solve(string &s, string &t)
    {
        // magic
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);

        int i = -1;
        for (auto tt : t)
        {
            i = s.find(tt, i + 1);
            if (i == -1)
            {
                return false;
            }
        }

        return true;
    }

    int numMatchingSubseq(string s, vector<string> &words)
    {
        int ans = 0;
        for (auto w : words)
        {
            if (solve(s, w))
            {
                ans++;
            }
        }

        return ans;
    }
};
