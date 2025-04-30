#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 27.40 MB (Beats 85.32 %).

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        const int n = nums.size();
        int num_freq[100] = {0};
        for (const auto nn : nums)
        {
            num_freq[nn - 1]++;
        }

        int ans = 0, idx = 0;
        while (true)
        {
            bool check = true;
            for (int i = 0; i < 100; i++)
            {
                if (num_freq[i] > 1)
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                return ans;
            }

            // op
            ans++;
            int j = 0;
            for (; j < 3 && idx + j < n; j++)
            {
                num_freq[nums[idx + j] - 1]--;
            }
            idx += j;
        }
        return -1;
    }
};
