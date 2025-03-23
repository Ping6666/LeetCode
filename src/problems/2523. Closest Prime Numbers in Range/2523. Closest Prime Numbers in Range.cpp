#include <vector>
using std::vector, std::min;

// without speed up
//   Runtime: 127 ms (Beats 77.04 %), Memory: 45.20 MB (Beats 21.30 %).

// with speed up
//   Runtime: 101 ms (Beats 78.52 %), Memory: 45.20 MB (Beats 21.30 %).

class Solution
{
private:
    vector<char> sieve_of_Eratosthenes(int n)
    {
        // ref. https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

        vector<char> table(n + 1, '#');
        table[0] = 'F';
        table[1] = 'F';
        for (int i = 2; (i * i) <= n; i++)
        {
            if (table[i] != '#')
            {
                continue;
            }

            table[i] = 'T';
            for (int j = i * i; j <= n; j += i)
            {
                table[j] = 'F';
            }
        }

        return table;
    }

    vector<char> sieve_of_Eratosthenes_speed_up(int l, int r, vector<int> &pair)
    {
        // ref. https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

        vector<char> table(r + 1, '#');
        table[0] = 'F';
        table[1] = 'F';

        int prev_prime = -1;
        for (int i = 2; (i * i) <= r; i++)
        {
            if (table[i] != '#')
            {
                continue;
            }

            table[i] = 'T';
            if (i >= l)
            {
                if (prev_prime != -1)
                {
                    if (i - prev_prime == 2)
                    {
                        pair[0] = prev_prime;
                        pair[1] = i;
                        return {};
                    }
                }
                prev_prime = i;
            }
            for (int j = i * i; j <= r; j += i)
            {
                table[j] = 'F';
            }
        }

        return table;
    }

public:
    vector<int> closestPrimes(int left, int right)
    {
        if (left <= 2 && right >= 3)
        {
            return {2, 3};
        }

        // vector<char> prime = sieve_of_Eratosthenes(right);

        vector<int> pair(2, -1);
        vector<char> prime = sieve_of_Eratosthenes_speed_up(left, right, pair);
        if (prime.size() == 0)
        {
            return pair;
        }

        int r = right;
        while (r >= left && prime[r] == 'F')
        {
            r--;
        }
        int l = r - 1;
        while (l >= left && prime[l] == 'F')
        {
            l--;
        }

        if (r < left || l < left)
        {
            return {-1, -1};
        }

        int ans_r = r, ans_l = l;

        while (r >= left && l >= left)
        {
            r = l;
            l = l - 1;
            while (l >= left && prime[l] == 'F')
            {
                l--;
            }

            if (l < left)
            {
                break;
            }

            if ((ans_r - ans_l) >= (r - l))
            {
                ans_r = r;
                ans_l = l;
            }
        }

        return {ans_l, ans_r};
    }
};
