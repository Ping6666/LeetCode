#include <vector>
#include <iostream>
using std::vector;

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
    // Runtime: 1629 ms (Beats 20.53 %), Memory: 32.95 MB (Beats 80.29 %).
    // not-in-place

public:
    int subarraySum(vector<int> &nums, int k)
    {
        int l = nums.size();

        int ans = 0;
        int sum;

        for (int i = 0; i < l; i++)
        {
            sum = nums[i];
            if (sum == k)
            {
                ans++;
            }

            for (int j = i + 1; j < l; j++)
            {
                sum += nums[j];
                if (sum == k)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};
