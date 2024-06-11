#include <vector>
#include <iostream>
using std::vector;

// Runtime: 69 ms (Beats 99.21 %), Memory: 123.46 MB (Beats 83.73 %).
// partially in-place

// the deletion will not affect the sequence and the result, since after deletion still need to check if beauitful.
// therefore the check can be done with greedy

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
public:
    int minDeletion(vector<int> &nums)
    {
        int l = nums.size();

        int ans = 0;
        for (int i = 0; i + 1 < l; i += 2)
        {
            if (nums[i] == nums[i + 1])
            {
                if (i + 2 < l)
                {
                    if (nums[i + 1] == nums[i + 2])
                    {
                        // since the nums is not sorted
                        nums[i + 1] = nums[i];
                    }
                }

                // do delection then shift idx front (for loop will do `i += 2`)
                ans++;
                i--;
            }
        }

        if ((l - ans) % 2 == 1)
        {
            ans++;
        }

        return ans;
    }
};
