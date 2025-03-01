#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 8.41 MB (Beats 70.42 %).

class Solution
{
public:
    string clearDigits(string s)
    {
        string ans = "";
        for (const auto &c : s)
        {
            if (c - '0' >= 0 && c - '0' <= 9)
            {
                // if (!ans.empty())
                ans.pop_back();
            }
            else
            {
                ans.push_back(c);
            }
        }

        return ans;
    }
};
