
// Runtime: 0 ms (Beats 100.00 %), Memory: 7.22 MB (Beats 94.54 %).

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        if (k == 1)
        {
            return '0';
        }

        int l = 1;
        for (int i = 1; i < n && l < k; i++)
        {
            l = l * 2 + 1;
        }

        // l will always be odd

        bool flip = false;
        while (k != ((l / 2) + 1) && k != 1)
        {
            // printf("%d %d\n", l, k);

            l /= 2;
            if (k > (l + 1))
            {
                k = 2 * (l + 1) - k;
                flip = !flip;
            }
        }

        if (k == 1)
        {
            return flip ? '1' : '0';
        }

        return flip ? '0' : '1';
    }
};

/*
#include <string>
using std::string;

// Runtime: 79 ms (Beats 18.09 %), Memory: 44.33 MB (Beats 50.17 %).

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        string s = "0";

        int l = 0;

        for (int i = 1; i < n; i++)
        {
            l = s.size();
            s += '1';

            for (int j = l - 1; j >= 0; j--)
            {
                if (s[j] == '1')
                {
                    s += '0';
                }
                else
                {
                    s += '1';
                }
            }
        }

        return s[k - 1];
    }
};
*/
