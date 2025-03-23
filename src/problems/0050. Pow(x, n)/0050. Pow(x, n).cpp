#include <stdio.h>

class Solution
{
    // Runtime: 0 ms (Beats 100 %), Memory: 5.9 MB (Beats 92.36 %).

private:
    double myLLPow(double x, long long n)
    {
        // use long long to solve overflow

        if (n < 0)
        {
            n = -1 * n;
            x = 1.0 / x;
        }

        double ans = 1;
        double curr_mul = x;

        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ans *= curr_mul;
            }

            curr_mul *= curr_mul;
            n = n / 2;
        }

        return ans;
    }

public:
    double myPow(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (x == 0 || x == 1)
        {
            return x;
        }

        return myLLPow(x, n);
    }
};

int main()
{
    Solution s;
    double ans;

    s = Solution();
    ans = s.myPow(2, 10);
    printf("%f\n", ans);

    s = Solution();
    ans = s.myPow(2.1, 3);
    printf("%f\n", ans);

    s = Solution();
    ans = s.myPow(2, -2);
    printf("%f\n", ans);

    s = Solution();
    ans = s.myPow(0.44528, 0);
    printf("%f\n", ans);

    s = Solution();
    ans = s.myPow(1, -2147483648);
    printf("%f\n", ans);

    return 0;
}
