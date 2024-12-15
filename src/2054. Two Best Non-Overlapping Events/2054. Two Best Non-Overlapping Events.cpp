#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 191 ms (Beats 18.92 %), Memory: 187.66 MB (Beats 6.88 %).

// ref. LeetCode Editorial - Approach 3: Greedy
// sweep line

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        vector<vector<int>> arr;
        for (const auto &e : events)
        {
            // start
            arr.push_back({e[0], 1, e[2]});
            // end
            arr.push_back({e[1] + 1, 0, e[2]});
        }

        sort(arr.begin(), arr.end());

        int ans = 0, _max_end = 0;
        for (const auto &a : arr)
        {
            if (a[1])
            {
                // start
                ans = max(ans, _max_end + a[2]);
            }
            else
            {
                // end
                _max_end = max(_max_end, a[2]);
            }
        }

        return ans;
    }
};
