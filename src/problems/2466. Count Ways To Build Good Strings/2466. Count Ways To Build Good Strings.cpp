
// Runtime: 2 ms (Beats 98.43 %), Memory: 8.14 MB (Beats 98.83 %).

class Solution
{
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        int dp[100001] = {0};
        dp[0] = 1;

        const int _mod = 1000000007;

        for (int i = 1; i <= high; i++)
        {
            if (i >= zero)
            {
                dp[i] += dp[i - zero];
            }
            if (i >= one)
            {
                dp[i] += dp[i - one];
            }
            dp[i] %= _mod;
        }

        int ans = 0;
        for (int i = low; i <= high; i++)
        {
            ans += dp[i];
            ans %= _mod;
        }
        return ans;
    }
};

/*
// TLE

class Solution
{
private:
    const int _mod = 1000000007;

    int countGoodString(const int len, const int &zero, const int &one)
    {
        long num_zero = 0, num_one = 0;

        num_zero = len / zero;
        num_one = (len - (num_zero * zero)) / one;

        while (num_zero * zero + num_one * one != len)
        {
            num_zero -= 1;
            num_one = (len - (num_zero * zero)) / one;
        }

        long ans = 0, temp;

        while (num_zero >= 0 && num_one >= 0)
        {
            temp = 1;
            for (int i = num_zero + 1; i <= (num_zero + num_one); i++)
            {
                temp *= i;
                temp %= this->_mod;
            }
            for (int i = 1; i <= num_one; i++)
            {
                temp /= i;
                temp %= this->_mod;
            }
            ans += temp;
            ans %= this->_mod;

            num_zero -= one;
            num_one += zero;

            // num_zero -= 1;
            // num_one = (len - (num_zero * zero)) / one;
            // while (num_zero * zero + num_one * one != len)
            // {
            //     num_zero -= 1;
            //     num_one = (len - (num_zero * zero)) / one;
            // }
        }

        return (int)ans;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        long ans = 0;

        for (int i = low; i <= high; i++)
        {
            ans += countGoodString(i, zero, one);
            // printf("%d %d\n", i, ans);
            ans %= this->_mod;
        }

        return (int)ans;
    }
};
*/
