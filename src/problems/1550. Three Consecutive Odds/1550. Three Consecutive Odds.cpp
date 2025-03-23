#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 10.45 MB (Beats 83.42 %).

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int count = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] % 2 == 1)
            {
                count++;

                if (count >= 3)
                {
                    return true;
                }
            }
            else
            {
                count = 0;
            }
        }

        return false;
    }
};
