#include <stdio.h>
#include <math.h> // ceil

#include <vector>

using namespace std;

class Solution
{
    // Runtime: 264 ms (Beats 95.54 %), Memory: 101.49 MB (Beats 67.19 %).

private:
    bool canMakeOnTime(vector<int> &dist, int speed, double hour)
    {
        double total = 0;

        for (int i = 0; i < dist.size(); i++)
        {
            double t = (double)dist[i] / speed;
            if (i != dist.size() - 1)
            {
                total += ceil(t);
            }
            else
            {
                total += t;
            }

            if (total > hour)
            {
                return false;
            }
        }

        return (total <= hour);
    }

public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int n = dist.size();

        if (n >= hour + 1)
        {
            return -1;
        }

        int max_dist = 0;
        for (int i = 0; i < n; i++)
        {
            if (max_dist < dist[i])
            {
                max_dist = dist[i];
            }
        }

        int l = 1;
        int r = max_dist; // 1e7
        int ret = -1;

        int m;
        bool check;

        while (l <= r)
        {
            m = l + (r - l) / 2;

            check = canMakeOnTime(dist, m, hour);

            if (check)
            {
                ret = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        if (ret == -1)
        {
            ret = floor((double)dist.back() / (hour - floor(hour))) - 1;

            while (true)
            {
                if (canMakeOnTime(dist, ret, hour))
                {
                    break;
                }

                ret += 1;
            }
        }

        return ret;
    }
};

int main()
{
    vector<int> dist;
    double hour;

    Solution s;
    int ans;

    dist = {1, 3, 2};
    hour = 6;
    s = Solution();
    ans = s.minSpeedOnTime(dist, hour);
    printf("%d\n", ans);

    dist = {1, 3, 2};
    hour = 2.7;
    s = Solution();
    ans = s.minSpeedOnTime(dist, hour);
    printf("%d\n", ans);

    dist = {1, 3, 2};
    hour = 1.9;
    s = Solution();
    ans = s.minSpeedOnTime(dist, hour);
    printf("%d\n", ans);

    dist = {1, 1, 100000};
    hour = 2.01;
    s = Solution();
    ans = s.minSpeedOnTime(dist, hour);
    printf("%d\n", ans);

    dist = {1, 1};
    hour = 1.0;
    s = Solution();
    ans = s.minSpeedOnTime(dist, hour);
    printf("%d\n", ans);

    return 0;
}
