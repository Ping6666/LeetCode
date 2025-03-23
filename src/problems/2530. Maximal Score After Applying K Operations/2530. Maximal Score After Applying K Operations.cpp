#include <vector>
#include <queue>
using std::vector, std::priority_queue;

// Runtime: 193 ms (Beats 63.59 %), Memory: 79.56 MB (Beats 71.57 %).

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int> table;
        for (const auto &n : nums)
        {
            table.push(n);
        }

        int tmp;
        long long ans = 0;
        for (int i = 0; i < k; i++)
        {
            tmp = table.top();
            table.pop();

            ans += tmp;

            // ceil(nums[i] / 3)
            if (tmp % 3 == 0)
            {
                table.push(tmp / 3);
            }
            else
            {
                table.push(tmp / 3 + 1);
            }
        }

        return ans;
    }
};
