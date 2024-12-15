#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map;

// Runtime: 88 ms (Beats 94.26 %), Memory: 98.27 MB (Beats 49.04 %).

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        // num to idx last seen
        unordered_map<int, int> table;

        long long ans = 0, sum = 0;

        int n, shift = 0;
        for (int i = 0; i < k; i++)
        {
            n = nums[i];
            sum += n;

            if (table.find(n) != table.end())
            {
                shift = max(shift, table[n] + 1);
                // printf("A %d\n", shift);
            }

            table[n] = i;
        }

        if (shift == 0)
        {
            ans = sum;
        }

        // printf("B %d\n", shift);

        for (int i = k; i < nums.size(); i++)
        {
            if (shift > 0)
            {
                shift--;
            }
            // printf("C %d\n", shift);

            n = nums[i];

            sum += n;
            sum -= nums[i - k];

            if (table.find(n) != table.end() &&
                (i - table[n] < k))
            {
                shift = max(shift, k - (i - table[n]));
            }

            if (shift == 0)
            {
                ans = max(ans, sum);
            }

            table[n] = i;
        }

        return ans;
    }
};
