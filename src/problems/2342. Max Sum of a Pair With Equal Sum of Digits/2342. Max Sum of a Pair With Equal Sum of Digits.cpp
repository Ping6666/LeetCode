#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map, std::pair, std::max, std::min;

// Runtime: 8 ms (Beats 92.65 %), Memory: 63.77 MB (Beats 87.26 %).

// Constraints:
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109

class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, pair<int, int>> table;
        for (const auto &n : nums)
        {
            // sum of digits
            int sd = 0;
            int _n = n;
            while (_n > 0)
            {
                sd += _n % 10;
                _n /= 10;
            }

            if (table.find(sd) == table.end())
            {
                // new
                table[sd] = {n, -1};
            }
            else
            {
                // update
                auto [n1, n2] = table[sd];
                if (n2 > n)
                {
                    continue;
                }
                else
                {
                    table[sd] = {max(n, n1), min(n, n1)};
                }
            }
        }

        int ans = -1;
        for (const auto &t : table)
        {
            if (t.second.second != -1)
            {
                ans = max(ans, t.second.first + t.second.second);
            }
        }
        return ans;
    }
};
