#include <string>
#include <vector>
using std::string, std::vector;

// Runtime: 59 ms (Beats 91.87 %), Memory: 26.76 MB (Beats 34.15 %).

// TODO seg.

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        char first_str[2] = {'a', 'b'}, second_str[2] = {'a', 'b'};

        if (x > y)
        {
            second_str[0] = 'b';
            second_str[1] = 'a';
        }
        else
        {
            int t = x;
            x = y;
            y = t;
            first_str[0] = 'b';
            first_str[1] = 'a';
        }

        int ans = 0;

        vector<char> v1;
        for (char c : s)
        {
            if (!v1.empty() && (c == first_str[1] && v1.back() == first_str[0]))
            {
                ans += x;
                v1.pop_back();
            }
            else
            {
                v1.push_back(c);
            }
        }

        vector<char> v2;
        for (char c : v1)
        {
            if (!v2.empty() && (c == second_str[1] && v2.back() == second_str[0]))
            {
                ans += y;
                v2.pop_back();
            }
            else
            {
                v2.push_back(c);
            }
        }

        return ans;
    }
};
