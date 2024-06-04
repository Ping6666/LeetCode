#include <string>
#include <unordered_map>
#include <vector>
using std::string, std::unordered_map, std::vector;

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 7.59 MB (Beats 99.62 %).

public:
    int longestPalindrome(string s)
    {
        vector<int> table(26 * 2, 0);

        for (auto c : s)
        {
            if ((c - 'a') >= 0 && (c - 'a') < 26)
            {
                table[(c - 'a')]++;
            }
            else
            {
                table[(c - 'A') + 26]++;
            }
        }

        int ans = 0;
        bool odd = false;
        for (auto t : table)
        {
            ans += t;
            if (t % 2 == 1)
            {
                if (!odd)
                {
                    odd = true;
                }
                else
                {
                    ans -= 1;
                }
            }
        }

        return ans;
    }
};

/*
class Solution
{
    // Runtime: 2 ms (Beats 63.38 %), Memory: 8.85 MB (Beats 62.59 %).

public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> table;

        for (auto c : s)
        {
            table[c]++;
        }

        int ans = 0;
        bool odd = false;
        for (auto t : table)
        {
            ans += t.second;
            if (t.second % 2 == 1)
            {
                if (!odd)
                {
                    odd = true;
                }
                else
                {
                    ans -= 1;
                }
            }
        }

        return ans;
    }
};
*/
