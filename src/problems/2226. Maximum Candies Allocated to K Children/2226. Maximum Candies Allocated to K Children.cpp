#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 31 ms (Beats 45.11 %), Memory: 88.06 MB (Beats 97.17 %).

class Solution
{
private:
    long long canFit(vector<int> &sorted_candies, int count)
    {
        if (count == 0)
        {
            return -1;
        }

        long long k = 0;
        for (const auto &c : sorted_candies)
        {
            // if (c < count)
            // {
            //     break;
            // }
            k += c / count;
        }
        return k;
    }

public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        // large first
        // sort(candies.rbegin(), candies.rend());

        int l = 0, r = 1e9, m = 0, ans = 0;
        long long t;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            // printf("%d %d %d\n", l, m, r);

            t = canFit(candies, m);
            if (t == -1 || t >= k)
            {
                l = m + 1;
                ans = m;
            }
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }
};
