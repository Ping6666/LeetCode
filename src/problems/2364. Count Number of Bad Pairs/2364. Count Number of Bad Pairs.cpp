#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map;

// Runtime: 66 ms (Beats 70.36 %), Memory: 87.62 MB (Beats 70.06 %).

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> table;

        long long good = 0;
        for (int i = 0; i < n; i++)
        {
            table[nums[i] - i]++;
            good += table[nums[i] - i] - 1;
        }
        n--;
        long long ans = 0;
        ans += ((1 + (long long)n) * n / 2) - good;
        return ans;
    }
};
