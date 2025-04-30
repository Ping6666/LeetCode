#include <vector>
#include <string>
#include <unordered_set>
using std::vector, std::string, std::unordered_set;

// Runtime: 297 ms (Beats 67.24 %), Memory: 18.44 MB (Beats 81.03 %).

class Solution
{
private:
    bool get_next(const int &n, vector<char> &v)
    {
        int idx = n - 1;

        while (idx >= 0)
        {
            if (v[idx] < '9')
            {
                v[idx]++;
                return true;
            }

            // last digit is '9'
            v[idx] = '0';
            idx--;
        }

        return false;
    }

    long long get_num(const int &n, vector<char> &v, bool overlap)
    {
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans *= 10;
            ans += v[i] - '0';
        }
        for (int i = overlap ? n - 1 : n - 2; i >= 0; i--)
        {
            ans *= 10;
            ans += v[i] - '0';
        }
        return ans;
    }

    string num_str(long long n)
    {
        string ans = "";

        int num_freq[10] = {0};

        long long _v = n;
        while (_v > 0)
        {
            num_freq[_v % 10]++;
            _v /= 10;
        }

        for (int i = 0; i < 10; i++)
        {
            if (num_freq[i] != 0)
            {
                ans += string(num_freq[i], '0' + i);
            }
        }
        return ans;
    }

    long long get_factorial(int n)
    {
        long long ans = 1;
        for (long long i = 1; i <= n; i++)
        {
            ans *= i;
        }
        return ans;
    }

    long long compute(const int n, string x)
    {
        int num_freq[10] = {0};

        for (auto c : x)
        {
            num_freq[c - '0']++;
        }

        long long ans = 0;
        if (num_freq[0] == 0)
        {
            long long _ans = get_factorial(n);
            for (int i = 0; i < 10; i++)
            {
                if (num_freq[i] != 0)
                {
                    _ans /= get_factorial(num_freq[i]);
                }
            }
            ans += _ans;
        }
        else
        {
            for (int j = 1; j < 10; j++)
            {
                if (num_freq[j] == 0)
                {
                    continue;
                }
                num_freq[j]--;

                long long _ans = get_factorial(n - 1);
                for (int i = 0; i < 10; i++)
                {
                    if (num_freq[i] != 0)
                    {
                        _ans /= get_factorial(num_freq[i]);
                    }
                }
                ans += _ans;

                num_freq[j]++;
            }
        }
        return ans;
    }

public:
    long long countGoodIntegers(int n, int k)
    {
        int _half_len = n / 2;
        if (n % 2 == 1)
        {
            _half_len++;
        }

        vector<char> v(_half_len, '0');
        v[0] = '1';

        unordered_set<string> k_palindromic;

        do
        {
            long long _v = get_num(_half_len, v, n % 2 == 0);

            if (_v % k == 0)
            {
                k_palindromic.insert(num_str(_v));
            }
        } while (get_next(_half_len, v));

        long long ans = 0;
        for (auto x : k_palindromic)
        {
            printf("%s\n", x.c_str());
            ans += compute(n, x);
        }
        return ans;
    }
};
