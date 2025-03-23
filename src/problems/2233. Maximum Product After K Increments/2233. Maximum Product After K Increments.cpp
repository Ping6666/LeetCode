#include <vector>
#include <algorithm>
#include <iostream>
using std::vector, std::sort, std::min;

// Runtime: 121 ms (Beats 98.42 %), Memory: 85.74 MB (Beats 93.04 %).

// [AM–GM inequality](https://en.wikipedia.org/wiki/AM%E2%80%93GM_inequality)
//   (x + y) / 2 >= sqrt(x * y) with equality if and only if x = y
// [right-to-left binary method modular exponentiation](https://en.wikipedia.org/wiki/Modular_exponentiation#Right-to-left_binary_method)

int MOD = 1e9 + 7;

class Solution
{

public:
    int mod(long long n)
    {
        return n % MOD;
    }

    int modular_pow(int base, int exponent)
    {
        // do pow(a, b)

        long long ans = 1, _base = base;
        while (exponent > 0)
        {
            if (exponent % 2 == 1)
            {
                ans = mod(ans * _base);
            }
            _base = mod(_base * _base);
            exponent >>= 1;
        }
        return ans;
    }

    int maximumProduct(vector<int> &nums, int k)
    {
        int l = nums.size();
        int sum = k;

        int mul = 0;
        for (auto n : nums)
        {
            sum += n;

            mul += sum / l;
            sum %= l;
        }

        sort(nums.begin(), nums.end());

        int idx, d;
        int v = nums[0], _v;

        for (idx = 1; idx < l && k > 0; idx++)
        {
            d = nums[idx] - v;
            // d will >= 0

            if (d > 0)
            {
                printf("before: %d %d %d\n", k, idx, d);

                // div into all value before
                _v = min(k / idx, d);

                v += _v;
                k -= _v * idx;

                printf("after: %d %d\n", _v, k);

                if (k < idx)
                {
                    // idx--;
                    break;
                }
            }
        }

        int ll = 0;
        if (k > 0)
        {
            // div into all value before
            _v = k / idx;

            v += _v;
            k -= _v * idx;

            ll = k;
        }

        printf("%d %d %d\n", idx, ll, v);

        long long ans;
        ans = modular_pow(v + 1, ll);
        if (idx > ll)
        {
            ans = mod(ans * modular_pow(v, idx - ll));
        }

        for (int j = idx; j < l; j++)
        {
            ans = mod(ans * nums[j]);
        }

        return (int)ans;
    }
};
