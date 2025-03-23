#include <math.h>

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.70 MB (Beats 91.08 %).

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        int _pow = pow(3, 15);

        while (true)
        {
            if (_pow <= n)
            {
                n -= _pow;
            }
            _pow /= 3;

            if (n == 0)
            {
                return true;
            }
            if (_pow == 0)
            {
                return false;
            }
        }
        return false;
    }
};
