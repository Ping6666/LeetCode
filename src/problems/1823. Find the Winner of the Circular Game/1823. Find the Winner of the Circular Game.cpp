#include <string.h> // memset

class Solution
{
    // Runtime: 9 ms (Beats 41.94 %), Memory: 6.97 MB (Beats 98.80 %).

public:
    int findTheWinner(int n, int k)
    {
        bool removed[n];
        memset(removed, false, sizeof(removed));

        int counter = n;
        int idx = 1, step;

        while (counter > 0)
        {
            step = k % counter;
            if (step == 0)
            {
                step = k;
            }

            int j = step;
            while (true)
            {
                if (!removed[idx - 1])
                {
                    // not found in removed
                    j--;
                    if (j == 0)
                    {
                        break;
                    }
                }

                idx++;
                if (idx > n)
                {
                    idx = 1;
                }
            }
            removed[idx - 1] = true;

            counter--;
        }

        return idx;
    }
};

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 6.94 MB (Beats 98.80 %).

public:
    int findTheWinner(int n, int k)
    {
        int ans = 0;
        for (int i = 2; i <= n; i++)
        {
            ans = (ans + k) % i;
        }
        return ans + 1;
    }
};
