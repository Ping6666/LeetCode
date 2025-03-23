// Runtime: 0 ms (Beats 100.00 %), Memory: 9.31 MB (Beats 17.13 %).
// n_mask can be remove, just use another for loop to check the mask

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        n--;
        if (n == 0)
        {
            return x;
        }

        int n_mask[64] = {0};
        int x_mask[64] = {0};

        int i = 0, _n = n, _x = x;
        while (_n > 0 || _x > 0)
        {
            if (_n % 2 == 1)
            {
                n_mask[i] = 1;
            }
            if (_x % 2 == 1)
            {
                x_mask[i] = 1;
            }
            // printf("%d %d %d\n", i, n_mask[i], x_mask[i]);

            _n /= 2;
            _x /= 2;
            i++;
        }

        long long ans = x;

        _n = 0, _x = 0;
        while (_x < 64)
        {
            if (x_mask[_x] == 0)
            {
                if (n_mask[_n] == 1)
                {
                    ans += ((long long)1 << _x);
                }
                _n++;
            }
            _x++;
        }

        return ans;
    }
};
