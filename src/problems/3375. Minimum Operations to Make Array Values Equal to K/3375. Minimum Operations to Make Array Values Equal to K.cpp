#include <vector>
using std::vector;

// Runtime: 3 ms (Beats 99.06 %), Memory: 31.52 MB (Beats 75.16 %).

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int num_freq[100] = {0};
        for (const int num : nums)
        {
            num_freq[num - 1]++;
        }

        int ans = 0;
        for (int i = 100; i > 0; i--)
        {
            if (num_freq[i - 1] != 0)
            {
                if (i > k)
                {
                    ans++;
                }
                if (i < k)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};
