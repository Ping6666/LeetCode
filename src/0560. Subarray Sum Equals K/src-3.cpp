#include <vector>
#include <iostream>
using std::vector;

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
    // Runtime: 2225 ms (Beats 17.32 %), Memory: 32.74 MB (Beats 96.21 %).
    // in-place

public:
    int subarraySum(vector<int> &nums, int k)
    {
        int l = nums.size();

        int ans = 0;

        for (int i = 0; i < l; i++)
        {
            if (nums[i] == k)
            {
                ans++;
            }

            for (int j = i + 1; j < l; j++)
            {
                nums[i] += nums[j];
                if (nums[i] == k)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};
