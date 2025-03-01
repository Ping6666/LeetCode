#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map;

// Runtime: 291 ms (Beats 85.89 %), Memory: 84.82 MB (Beats 81.50 %).

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        unordered_map<int, int> table;

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                table[nums[i] * nums[j]]++;
            }
        }

        int ans = 0;
        int c;
        for (const auto &t : table)
        {
            // printf("%d %d\n", t.first, t.second);

            c = t.second - 1;
            if (c == 0)
            {
                continue;
            }

            ans += (1 + c) * c * 4;
        }
        return ans;
    }
};
