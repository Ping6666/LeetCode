#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map;

class Solution
{
    // Runtime: 3 ms (Beats 92.09 %), Memory: 27.51 MB (Beats 47.30 %).

public:
    int duplicateNumbersXOR(vector<int> &nums)
    {
        int ans = 0;

        unordered_map<int, int> counter;
        for (int i = 0; i < nums.size(); i++)
        {
            counter[nums[i]]++;
        }

        for (auto &it : counter)
        {
            if (it.second == 2)
            {
                ans ^= it.first;
            }
        }

        return ans;
    }
};
