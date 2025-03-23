#include <string>
using std::string;

// Runtime: 16 ms (Beats 90.91 %), Memory: 42.70 MB (Beats 77.67 %).

class Solution
{
public:
    string makeFancyString(string s)
    {
        string ans = "";

        int counter = 0;
        char _prev = ' ';
        for (const auto &c : s)
        {
            if (counter == 0)
            {
                _prev = c;
                counter++;
            }
            else
            {
                if (_prev == c)
                {
                    if (counter == 2)
                    {
                        continue;
                    }
                    counter++;
                }
                else
                {
                    _prev = c;
                    counter = 1;
                }
            }

            ans += c;
        }

        return ans;
    }
};
