#include <math.h>
using std::sqrt;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.05 MB (Beats 61.35 %).
// math

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long long l = 0, r = (long long)sqrt(c);

        while (l <= r)
        {
            if (l * l + r * r == c)
            {
                return true;
            }
            else if (l * l + r * r > c)
            {
                r--;
            }
            else
            {
                l++;
            }
        }

        return false;
    }
};
