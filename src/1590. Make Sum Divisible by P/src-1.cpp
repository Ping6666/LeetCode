#include <vector>
#include <unordered_set>
using std::vector, std::unordered_set;

// TLE

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size();

        int sum = 0;
        vector<int> prefix_sum;

        vector<unordered_set<int>> table(n);

        for (int i = 0; i < n; i++)
        {
            sum = (sum + nums[i]) % p;
            prefix_sum.push_back(nums[i] % p);
            for (int j = 0; j < i; j++)
            {
                prefix_sum[j] = (prefix_sum[j] + nums[i]) % p;
            }

            for (int j = 0; j < i + 1; j++)
            {
                table[i - j].insert(prefix_sum[j] % p);
            }
        }

        int r = sum % p;
        if (r == 0)
        {
            return 0;
        }

        int ans = -1;
        for (int i = 0; i < n - 1; i++)
        {
            if (table[i].find(r) != table[i].end())
            {
                ans = i + 1;
                break;
            }
        }

        return ans;
    }
};
