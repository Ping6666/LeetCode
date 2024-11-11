#include <vector>
using std::vector;

// Runtime: 27 ms (Beats 73.13 %), Memory: 59.97 MB (Beats 99.40 %).

class Solution
{
public:
    int largestCombination(vector<int> &candidates)
    {
        int max_count = 0;
        for (int i = 0; i < 24; i++)
        {
            int count = 0;
            for (const auto &n : candidates)
            {
                if ((n & (1 << i)) != 0)
                {
                    count++;
                }
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }
};
