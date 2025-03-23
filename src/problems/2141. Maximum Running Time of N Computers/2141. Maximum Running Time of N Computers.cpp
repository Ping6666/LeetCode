#include <stdio.h>
#include <math.h>

#include <vector>
#include <algorithm> // sort

using namespace std;

class Solution
{
    // Runtime: 129 ms (Beats 99.64 %), Memory: 55.79 MB (Beats 71.58 %).

public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        int num_batteries = batteries.size();
        long long total = 0;
        for (int i = 0; i < num_batteries; i++)
        {
            total += batteries[i];
        }

        long long l = 0, r = total / n;
        long long m, extra;
        long long ans = -1;

        while (l <= r)
        {
            m = l + (r - l) / 2;

            extra = 0;
            for (int i = 0; i < num_batteries; i++)
            {
                extra += min((long long)batteries[i], m);
            }

            if (extra / n >= m)
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return ans;
    }
};

/*
class Solution
{
    // Runtime: 113 ms (Beats 100 %), Memory: 57.1 MB (Beats 15.47 %).

public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        int num_batteries = batteries.size();
        vector<long long> runTime(n, 0LL);
        long long extra = 0LL;

        // cause batteries are interchangeable so can use extra to compute the time

        sort(batteries.begin(), batteries.end());

        for (int i = 0; i < n; i++)
        {
            runTime[n - i - 1] += batteries[num_batteries - i - 1];
        }

        for (int i = 0; i < num_batteries - n; i++)
        {
            extra += batteries[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            if ((extra / (i + 1)) < (runTime[i + 1] - runTime[i]))
            {
                return runTime[i] + (extra / (i + 1));
            }

            extra -= ((i + 1) * (runTime[i + 1] - runTime[i]));
        }

        return runTime.back() + (extra / n);
    }
};
*/

/*
class Solution
{
    // Time Limit Exceeded

public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        // 1 <= n <= batteries.length <= 105

        int num_batteries = batteries.size();
        long long runTime = 0;

        int consume = 0;

        while (true)
        {
            sort(batteries.begin(), batteries.end());

            if (num_batteries - n - 1 >= 0 && batteries[num_batteries - n - 1] != 0)
            {
                consume = batteries[num_batteries - n] - batteries[num_batteries - n - 1] + 1;
            }
            else
            {
                consume = batteries[num_batteries - n];
            }

            if (consume <= 0)
            {
                break;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    batteries[num_batteries - i - 1] -= consume;
                }
                runTime += consume;
            }
        }

        return runTime;
    }
};
*/

int main()
{
    int n;
    vector<int> batteries;

    Solution s;
    long long ans;

    n = 2;
    batteries = {3, 3, 3};
    s = Solution();
    ans = s.maxRunTime(n, batteries);
    printf("%lld\n", ans);

    n = 2;
    batteries = {1, 1, 1, 1};
    s = Solution();
    ans = s.maxRunTime(n, batteries);
    printf("%lld\n", ans);

    n = 3;
    batteries = {10, 10, 3, 5};
    s = Solution();
    ans = s.maxRunTime(n, batteries);
    printf("%lld\n", ans);

    return 0;
}
