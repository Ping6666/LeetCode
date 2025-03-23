#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.81 MB (Beats 96.48 %).

int isPalindromic(long long n)
{
    char arr[10] = {'0'};
    int len = 0;

    while (n > 0)
    {
        arr[len] = n % 10 + '0';
        n /= 10;
        len++;
    }

    for (int i = 0; i < len / 2; i++)
    {
        if (arr[i] != arr[len - i - 1])
        {
            return 0;
        }
    }
    return len;
}

int nextPalindromic(long long n, int len, bool up)
{
    if (n == 11 && !up)
    {
        // special case
        return -1;
    }

    // given n need to be a palindromic
    int p = 1;
    for (int i = 0; i < (len / 2); i++)
    {
        p *= 10;
    }

    int _n = (n / p) % 10;
    bool is_odd = len % 2 == 1;

    if (up)
    {
        if (_n < 9)
        {
            if (is_odd)
            {
                return p;
            }
            else
            {
                return p / 10 + p;
            }
        }
    }
    else
    {
        if (_n > 0)
        {
            if (is_odd)
            {
                return p;
            }
            else
            {
                return p / 10 + p;
            }
        }
    }

    // need brute force
    return -1;
}

class Solution
{
public:
    string nearestPalindromic(string n)
    {
        // for (int i = 1; i < 10000; i++)
        // {
        //     int a = isPalindromic(i);
        //     if (a != 0)
        //     {
        //         int b = nextPalindromic(i, a, true);
        //         int c = nextPalindromic(i, a, false);
        //         printf("%d %d %d\n", i, b, c);
        //     }
        // }

        // hit the palindromic first
        // then check up or down

        int _size = n.size();
        int half_size = _size / 2;
        long long num_ori = std::stoll(n);

        for (int i = 0; i < half_size; i++)
        {
            n[_size - 1 - i] = n[i];
        }
        long long p_curr = std::stoll(n);

        long long p_prev = p_curr, p_next = p_curr;

        bool check_prev = false, check_next = false;
        if (p_curr >= num_ori)
        {
            p_prev = nextPalindromic(p_curr, _size, false);
            if (p_prev < 0)
            {
                check_prev = true;
            }

            p_prev = p_curr - p_prev;
        }
        if (p_curr <= num_ori)
        {
            p_next = nextPalindromic(p_curr, _size, true);
            if (p_next < 0)
            {
                check_next = true;
            }

            p_next = p_curr + p_next;
        }

        int check;
        if (check_prev)
        {
            check = 0;
            p_prev = p_curr;
            while (check <= 0)
            {
                p_prev--;
                check = isPalindromic(p_prev);
            }
        }
        if (check_next)
        {
            check = 0;
            p_next = p_curr;
            while (check <= 0)
            {
                p_next++;
                check = isPalindromic(p_next);
            }
        }

        // printf("%d\n", num_ori);
        // printf("%d\n", p_curr);
        // printf("%d\n", p_next);
        // printf("%d\n", p_prev);

        if ((p_next - num_ori) < (num_ori - p_prev))
        {
            return std::to_string(p_next);
        }

        return std::to_string(p_prev);
    }
};
