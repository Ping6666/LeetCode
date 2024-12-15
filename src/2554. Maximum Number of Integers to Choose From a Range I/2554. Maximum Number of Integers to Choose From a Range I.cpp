#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 42 ms (Beats 92.37 %), Memory: 117.51 MB (Beats 88.15 %).

class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        int n1 = banned.size();
        sort(banned.begin(), banned.end());

        int idx = 0, c = 0;
        for (int i = 1; i <= n && maxSum >= i; i++)
        {
            if (idx < n1)
            {
                if (banned[idx] < i)
                {
                    // dulp. num. may in the banned arr.
                    idx++;
                    i--;
                    continue;
                }
                if (banned[idx] == i)
                {
                    idx++;
                    continue;
                }
            }

            maxSum -= i;
            c++;
        }

        return c;
    }
};
