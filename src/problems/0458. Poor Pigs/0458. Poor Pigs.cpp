#include <math.h>

class Solution
{
    // Runtime: 0 ms (100.00 %), Memory: 6.3 MB (25.56 %).
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int baseNum = (minutesToTest / minutesToDie) + 1;
        int exponentNum = 0;
        while (pow(baseNum, exponentNum) < buckets)
            exponentNum++;
        return exponentNum;
    }
};
