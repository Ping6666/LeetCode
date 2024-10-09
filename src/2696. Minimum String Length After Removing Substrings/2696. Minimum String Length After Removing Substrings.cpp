#include <string>
#include <stack>
using std::string, std::stack;

// Runtime: 4 ms (Beats 76.08 %), Memory: 11.49 MB (Beats 72.37 %).

class Solution
{
public:
    int minLength(string s)
    {
        int n = s.size();
        stack<char> table;

        char prev, curr;
        for (const auto &curr : s)
        {
            prev = table.empty() ? ' ' : table.top();

            if ((prev == 'A' && curr == 'B') ||
                (prev == 'C' && curr == 'D'))
            {
                table.pop();
            }
            else
            {
                table.push(curr);
            }
        }

        return table.size();
    }
};
