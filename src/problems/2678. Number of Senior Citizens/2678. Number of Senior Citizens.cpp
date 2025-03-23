#include <vector>
#include <string>
using std::vector, std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 17.34 MB (Beats 35.30 %).

class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int n = details.size(), c = 0;
        for (int i = 0; i < n; i++)
        {
            if (details[i][11] > '6')
            {
                c++;
            }
            else if (details[i][11] == '6')
            {
                if (details[i][12] >= '1')
                {
                    c++;
                }
            }
        }

        return c;
    }
};
