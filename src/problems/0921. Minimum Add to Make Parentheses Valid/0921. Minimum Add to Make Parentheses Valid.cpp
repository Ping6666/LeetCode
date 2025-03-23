#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.70 MB (Beats 94.13 %).

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int counter = 0;
        int ans = 0;
        for (const auto &c : s)
        {
            if (c == '(')
            {
                counter++;
            }
            else
            {
                if (counter > 0)
                {
                    counter--;
                }
                else
                {
                    ans++;
                }
            }
        }

        return ans + counter;
    }
};
