#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 16.95 MB (Beats 68.43 %).

class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        int num_freq[500] = {0};
        for (const auto &n : nums)
        {
            num_freq[n - 1]++;
        }

        for (int i = 0; i < 500; i++)
        {
            if (num_freq[i] % 2 != 0)
            {
                return false;
            }
        }
        return true;
    }
};
