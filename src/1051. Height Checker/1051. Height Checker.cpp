#include <vector>
#include <algorithm>
using std::vector, std ::sort;

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 10.04 MB (Beats 78.64 %).

public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> sh(heights);

        sort(sh.begin(), sh.end());

        int ans = 0;
        for (int i = 0; i < sh.size(); i++)
        {
            if (sh[i] != heights[i])
            {
                ans++;
            }
        }

        return ans;
    }
};
