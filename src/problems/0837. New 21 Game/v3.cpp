#include <vector>

using std::vector, std::max;

// interval

class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        vector<double> prefix_sum = vector<double>(max(k + maxPts + 1, n + 1));
        prefix_sum[0]++; // 0
        prefix_sum[1]--;

        double p = 0;
        for (int i = 0; i < k; i++)
        {
            p += prefix_sum[i];
            double v = p / maxPts;
            prefix_sum[i + 1] += v;
            prefix_sum[maxPts + i + 1] -= v;
        }

        double ans = 0;
        // sum up [k, n]
        for (int j = k; j <= n; j++)
        {
            p += prefix_sum[j];
            ans += p;
        }
        return ans;
    }
};
