#include <vector>

using std::vector, std::max;

class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        vector<double> prefix_sum = vector<double>(max(k + maxPts + 1, n + 1));
        prefix_sum[0]++; // 0

        for (int i = 0; i < k; i++)
        {
            double v = prefix_sum[i];
            v /= maxPts;
            for (int j = i + 1; j < maxPts + i + 1; j++)
            {
                prefix_sum[j] += v;
            }
        }

        double ans = 0;
        // sum up [k, n]
        for (int j = k; j <= n; j++)
        {
            ans += prefix_sum[j];
        }
        return ans;
    }
};
