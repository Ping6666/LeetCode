#include <string>
using std::string, std::min;

// Runtime: 0 ms (Beats 100.00 %), Memory: 8.24 MB (Beats 92.08 %).

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        const int n = blocks.size();

        int recolors = 0;
        for (int i = 0; i < k; i++)
        {
            if (blocks[i] != 'B')
            {
                recolors++;
            }
        }

        int ans = recolors;
        for (int i = k; i < n; i++)
        {
            if (blocks[i] != blocks[i - k])
            {
                // a change

                recolors += blocks[i] == 'B' ? -1 : 1;

                ans = min(ans, recolors);
            }
        }
        return ans;
    }
};
