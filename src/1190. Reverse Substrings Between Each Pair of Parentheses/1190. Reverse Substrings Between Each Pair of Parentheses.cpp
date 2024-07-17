#include <string>
#include <algorithm>
using std::string, std::reverse;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.47 MB (Beats 84.88 %).

class Solution
{
private:
    void reverseSubstring(string &s, int i, int j)
    {
        // [i, j]

        int left_idx = -1, count = 0;
        for (int idx = i; idx <= j; idx++)
        {
            if (left_idx == -1 && s[idx] == '(')
            {
                left_idx = idx;
                count = 0;
            }
            else if (left_idx != -1 && s[idx] == '(')
            {
                count++;
            }
            else if (left_idx != -1 && s[idx] == ')')
            {
                if (count == 0)
                {
                    reverseSubstring(s, left_idx + 1, idx - 1);
                    left_idx = -1;
                }

                count--;
            }
        }

        if (i != 0)
        {
            reverse(s.begin() + i, s.begin() + j + 1);
        }
        return;
    }

public:
    string reverseParentheses(string s)
    {
        reverseSubstring(s, 0, s.size() - 1);

        // ref. https://stackoverflow.com/a/20326454
        s.erase(std::remove(s.begin(), s.end(), '('), s.end());
        s.erase(std::remove(s.begin(), s.end(), ')'), s.end());

        return s;
    }
};
