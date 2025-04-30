// WA + TLE

class Solution
{
private:
    const int _mod = 1e9 + 7;

    int mod_inv(long long a)
    {
        return power(a, _mod - 2);
    }

    // Fast exponentiation to compute a^b % mod
    int power(long long a, int b)
    {
        a = a % _mod;

        int result = 1;
        while (b > 0)
        {
            if (b % 2 == 1)
            {
                result = (result * a) % _mod;
            }
            a = (a * a) % _mod;
            b /= 2;
        }
        return result;
    }

    int get_op(int n, int op)
    {
        if (n == 0)
        {
            return 0;
        }
        if (op == 1)
        {
            return 1;
        }

        // compute binomial coefficient
        //   op - 1 + n
        // C
        //   op - 1

        long long ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans * (op + i - 1)) % _mod;
            ans = (ans * mod_inv(i)) % _mod;
        }
        return (int)ans;
    }

public:
    int idealArrays(int n, int maxValue)
    {
        if (n == 1)
        {
            return maxValue;
        }

        int ans = idealArrays(n - 1, maxValue);
        int pd = -1, pd_ans = 0;
        for (int i = 2; i <= maxValue; i++)
        {
            if (pd != maxValue / i)
            {
                pd = maxValue / i;
                pd_ans = get_op(n - 1, pd);
            }
            ans = (ans + pd_ans) % _mod;
        }
        return ans;
    }
};
