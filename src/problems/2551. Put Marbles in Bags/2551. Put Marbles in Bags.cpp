#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 32 ms (Beats 81.43 %), Memory: 67.36 MB (Beats 63.29 %).

class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        const int n = weights.size();
        vector<int> pair_sum;
        for (int i = 0; i < n - 1; i++)
        {
            pair_sum.push_back(weights[i] + weights[i + 1]);
        }

        sort(pair_sum.begin(), pair_sum.end());

        long long ans = 0;
        for (int i = 0; i < k - 1; i++)
        {
            ans += pair_sum[n - 2 - i] - pair_sum[i];
        }
        return ans;
    }
};
