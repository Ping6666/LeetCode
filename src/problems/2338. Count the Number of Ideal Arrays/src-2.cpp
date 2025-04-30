#include <vector>
using std::vector;

const int MOD = 1e9 + 7;
const int max_V = 1e4 + 1, max_N = 1e4 + 1;
const int max_P = 14; // ceil(log2(max_v))

int sieve[max_V + 1];
vector<int> prime_factor[max_N + 1];
int c[max_V + max_P + 2][max_P + 2];

// ref.: LeetCode Eidtorial - Approach: Combinatorial Mathematics
// Runtime: 3 ms (Beats 91.74 %), Memory: 9.73 MB (Beats 68.81 %).

class Solution
{
public:
    Solution()
    {
        if (c[0][0])
            return;

        for (int i = 2; i <= max_V; i++)
        {
            if (sieve[i] == 0)
            {
                for (int ii = i; ii <= max_V; ii += i)
                {
                    sieve[ii] = i;
                }
            }
        }

        for (int i = 2; i <= max_V; i++)
        {
            int ii = i;
            while (ii > 1)
            {
                int p = sieve[ii];
                int count = 0;
                while (ii % p == 0)
                {
                    ii /= p;
                    count++;
                }
                prime_factor[i].push_back(count);
            }
        }

        c[0][0] = 1;
        for (int i = 1; i <= max_N + max_P + 1; i++)
        {
            c[i][0] = 1;
            for (int j = 1; j <= max_P + 1; j++)
            {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
            }
        }
    }

    int idealArrays(int n, int maxValue)
    {
        int ans = 0;
        for (int i = 1; i <= maxValue; i++)
        {
            long long _ans = 1;
            for (auto count : prime_factor[i])
            {
                _ans = (_ans * c[n + count - 1][count]) % MOD;
            }
            ans = (ans + _ans) % MOD;
        }
        return ans;
    }
};
