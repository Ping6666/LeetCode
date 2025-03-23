class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 7.22 MB (Beats 75.25 %).

public:
    int findComplement(int num)
    {
        int ans = 0;
        unsigned int r = 1;
        while (num > 0)
        {
            if (num % 2 == 0)
            {
                // flip
                ans += r;
            }
            num /= 2;
            r *= 2;
        }

        return ans;
    }
};

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 7.26 MB (Beats 75.25 %).

public:
    int findComplement(int num)
    {
        int arr[31] = {0};
        int i = 0;
        while (num > 0)
        {
            if (num % 2 == 0)
            {
                // flip
                arr[i] = 1;
            }
            num /= 2;
            i++;
        }

        int ans = 0;
        for (int i = 31 - 1; i >= 0; i--)
        {
            ans *= 2;
            if (arr[i] == 1)
            {
                ans++;
            }
        }

        return ans;
    }
};
