#include <string>
#include <queue>
using std::string, std::priority_queue, std::pair;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.62 MB (Beats 78.90 %).

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int, char>> table;
        if (a > 0)
        {
            table.emplace(a, 'a');
        }
        if (b > 0)
        {
            table.emplace(b, 'b');
        }
        if (c > 0)
        {
            table.emplace(c, 'c');
        }

        string s = "";

        while (!table.empty())
        {
            auto t = table.top();
            table.pop();

            int count = t.first;
            char c = t.second;

            int n = s.size();
            if (n >= 2 && (s[n - 1] == c && s[n - 2] == c))
            {
                if (table.empty())
                {
                    break;
                }

                auto t1 = table.top();
                table.pop();

                int count1 = t1.first - 1;
                char c1 = t1.second;

                s += c1;

                if (count1 > 0)
                {
                    table.emplace(count1, c1);
                }
            }
            else
            {
                count--;
                s += c;
            }

            if (count > 0)
            {
                table.emplace(count, c);
            }
        }

        return s;
    }
};
