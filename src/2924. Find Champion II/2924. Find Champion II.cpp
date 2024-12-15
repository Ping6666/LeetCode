#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 93.69 MB (Beats 66.75 %).

class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> in_count(n, 0);
        for (const auto &e : edges)
        {
            in_count[e[1]]++;
        }

        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (in_count[i] == 0)
            {
                if (ans == -1)
                {
                    ans = i;
                }
                else
                {
                    return -1;
                }
            }
        }

        return ans;
    }
};
