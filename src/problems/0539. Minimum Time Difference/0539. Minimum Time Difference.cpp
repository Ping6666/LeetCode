#include <vector>
#include <string>
#include <algorithm>
using std::vector, std::string, std::sort;

// Runtime: 3 ms (Beats 99.58 %), Memory: 17.40 MB (Beats 95.56 %).

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> time_vec;
        for (const auto &s : timePoints)
        {
            time_vec.push_back(((s[0] - '0') * 10 + (s[1] - '0')) * 60 +
                               ((s[3] - '0') * 10 + (s[4] - '0')));
        }
        sort(time_vec.begin(), time_vec.end());

        int n = time_vec.size();
        int ans = time_vec[0] + 1440 - time_vec[n - 1];

        int c_diff;
        for (int i = 1; i < n; i++)
        {
            c_diff = time_vec[i] - time_vec[i - 1];
            if (c_diff < ans)
            {
                ans = c_diff;
            }
        }

        return ans;
    }
};
