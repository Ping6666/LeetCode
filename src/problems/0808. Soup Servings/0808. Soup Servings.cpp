#include <stdio.h>
#include <math.h>

#include <unordered_map>

using namespace std;

class Solution
{
    // Runtime: 0 ms (Beats 100 %), Memory: 6.28 MB (Beats 95.06 %).

private:
    double dp[200][200];

    double solveSoupServings(int a, int b)
    {
        // a: remanence of A soup
        // b: remanence of B soup
        if (a <= 0 && b <= 0)
        {
            return 0.5;
        }
        else if (a <= 0)
        {
            return 1.0;
        }
        else if (b <= 0)
        {
            return 0.0;
        }

        if (dp[a][b] > 0)
        {
            return dp[a][b];
        }

        dp[a][b] = (0.25 * (solveSoupServings(a - 4, b) +
                            solveSoupServings(a - 3, b - 1) +
                            solveSoupServings(a - 2, b - 2) +
                            solveSoupServings(a - 1, b - 3)));

        return dp[a][b];
    }

public:
    double soupServings(int n)
    {
        if (n > 4800)
        {
            return 1.0;
        }

        int m = ceil(n / 25.0);
        return solveSoupServings(m, m);
    }
};

/*
class Solution
{
    // Runtime: 0 ms (Beats 100 %), Memory: 10.73 MB (Beats 52.23 %).

private:
    unordered_map<int, unordered_map<int, double>> dp;

    double solveSoupServings(int a, int b)
    {
        // a: remanence of A soup
        // b: remanence of B soup
        if (a <= 0 && b <= 0)
        {
            return 0.5;
        }
        else if (a <= 0)
        {
            return 1.0;
        }
        else if (b <= 0)
        {
            return 0.0;
        }

        if (dp[a].find(b) != dp[a].end())
        {
            return dp[a][b];
        }

        dp[a][b] = (0.25 * (solveSoupServings(a - 4, b) +
                            solveSoupServings(a - 3, b - 1) +
                            solveSoupServings(a - 2, b - 2) +
                            solveSoupServings(a - 1, b - 3)));

        return dp[a][b];
    }

public:
    double soupServings(int n)
    {
        // some speed up
        if (n > 4800)
        {
            return 1.0;
        }

        int m = ceil(n / 25.0);
        return solveSoupServings(m, m);
    }
};
*/

int main()
{
    int n;
    Solution s;
    double ans;

    n = 50;
    s = Solution();
    ans = s.soupServings(n);
    printf("%f\n", ans);

    n = 100;
    s = Solution();
    ans = s.soupServings(n);
    printf("%f\n", ans);

    n = 500;
    s = Solution();
    ans = s.soupServings(n);
    printf("%f\n", ans);

    return 0;
}
