#include <vector>
using std::vector;

// Runtime: 51 ms (Beats 98.33 %), Memory: 102.53 MB (Beats 91.84 %).

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        const int n = colors.size();
        int ans = 0;

        int prev_color = colors[0], alt_count = 1;
        for (int i = 1, ii; i < n + k - 1; i++)
        {
            ii = i % n;

            if (prev_color == colors[ii])
            {
                alt_count = 1;
                prev_color = colors[ii];
                continue;
            }

            alt_count++;

            if (alt_count >= k)
            {
                ans++;
            }

            prev_color = colors[ii];
        }

        return ans;
    }
};
