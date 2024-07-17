#include <vector>
#include <string>
using std::vector, std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 13.80 MB (Beats 96.60 %).

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int n = 0;
        for (const auto &log : logs)
        {
            if (log[0] == '.')
            {
                if (log[1] == '.')
                {
                    n--;
                    if (n < 0)
                    {
                        n = 0;
                    }
                }
            }
            else
            {
                n++;
            }
        }

        return n;
    }
};
