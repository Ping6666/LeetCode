#include <vector>
using std::vector;

// Runtime: 62 ms (Beats 90.48 %), Memory: 85.86 MB (Beats 63.29 %).

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int bill_5 = 0;
        int bill_10 = 0;
        for (const auto &b : bills)
        {
            if (b == 5)
            {
                bill_5++;
            }
            else if (b == 10)
            {
                bill_5--;
                bill_10++;
            }
            else if (b == 20)
            {
                if (bill_10 > 0)
                {
                    bill_10--;
                    bill_5--;
                }
                else
                {
                    bill_5 -= 3;
                }
            }

            if (bill_5 < 0)
            {
                return false;
            }
        }

        return true;
    }
};
