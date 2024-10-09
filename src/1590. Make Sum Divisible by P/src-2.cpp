#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map;

// Runtime: 117 ms (Beats 96.14 %), Memory: 70.31 MB (Beats 85.60 %).

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();
        int sum = 0;

        for (const auto &_n : nums)
        {
            sum += _n;
            sum %= p;
        }

        sum %= p;
        if (sum == 0)
        {
            return 0;
        }

        unordered_map<int, int> table;
        table[0] = -1;

        int curr_sum = 0, min_len = n, tmp;

        for (int i = 0; i < n; i++)
        {
            curr_sum += nums[i];
            curr_sum %= p;

            tmp = (curr_sum - sum + p) % p;

            if (table.find(tmp) != table.end())
            {
                min_len = min(min_len, i - table[tmp]);
            }

            table[curr_sum] = i;
        }

        return min_len == n ? -1 : min_len;
    }
};
