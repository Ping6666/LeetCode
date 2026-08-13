#include <deque>

using std::deque;

// TLE

class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        deque<double> prefix_sum;

        for (int j = 0; j < maxPts; j++)
        {
            // [1, maxPts]
            prefix_sum.push_back(0);
        }
        prefix_sum[0]++; // 0

        for (int i = 0; i < k; i++)
        {
            double v = prefix_sum.front();
            v /= maxPts;

            prefix_sum.pop_front();
            prefix_sum.push_back(0);
            for (int j = 0; j < maxPts; j++)
            {
                prefix_sum[j] += v;
            }
        }

        double ans = 0;
        // j = 0 -> k
        for (int j = 0; j <= n - k; j++)
        {
            // sum up [k, n]
            ans += prefix_sum[j];
        }

        return ans;
    }
};
