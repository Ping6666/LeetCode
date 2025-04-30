// Runtime: 0 ms (Beats 100.00 %), Memory: 7.84 MB (Beats 69.99 %).

class Solution
{
private:
    long long modpow(long long base, long long exponent, long long modulus)
    {
        base %= modulus;

        long long result = 1;
        while (exponent > 0)
        {
            if (exponent % 2 == 1)
            {
                result = (result * base) % modulus;
            }
            base = (base * base) % modulus;
            exponent >>= 1;
        }
        return result;
    }

public:
    int countGoodNumbers(long long n)
    {
        const int MOD = 1e9 + 7;

        long long even_count = n / 2;
        const int even_op = 5; // 0, 2, 4, 6, 8

        long long odd_count = n / 2;
        const int odd_op = 4; // 2, 3, 5, 7

        if (n % 2 == 1)
        {
            even_count++;
        }

        long long ans = 1;
        ans = (ans * modpow(even_op, even_count, MOD)) % MOD;
        ans = (ans * modpow(odd_op, odd_count, MOD)) % MOD;
        return (int)ans;
    }
};
