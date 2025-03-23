#include <string>
#include <vector>
using std::string, std::vector;

// Runtime: 31 ms (Beats 97.78 %), Memory: 33.81 MB (Beats 87.14 %).

class Solution
{
private:
    bool mask[26] = {false};

public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        for (const auto &a : allowed)
        {
            mask[a - 'a'] = true;
        }

        int ans = 0;
        bool good;
        for (const auto &w : words)
        {
            good = true;
            for (const auto &_w : w)
            {
                if (!mask[_w - 'a'])
                {
                    good = false;
                    break;
                }
            }

            if (good)
            {
                ans++;
            }
        }

        return ans;
    }
};
