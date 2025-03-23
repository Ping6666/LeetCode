#include <vector>
using std::vector, std::max;

// Runtime: 98 ms (Beats 18.82 %), Memory: 60.99 MB (Beats 64.15 %).

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int bit_arr[32] = {0};

        int ans = 1;

        const int n = nums.size();
        int l = 0, r = 0, t;
        while (r < n)
        {
            // add nums[r]
            t = nums[r];
            for (int i = 0; i < 32 && t > 0; i++)
            {
                if (t & 1 == 1)
                {
                    bit_arr[i]++;
                }
                t >>= 1;
            }

            while (l < r)
            {
                bool check = true;
                for (int i = 0; i < 32 && check; i++)
                {
                    if (bit_arr[i] > 1)
                    {
                        check = false;
                    }
                }

                if (!check)
                {
                    // remove nums[l]
                    t = nums[l];
                    for (int i = 0; i < 32 && t > 0; i++)
                    {
                        if (t & 1 == 1)
                        {
                            bit_arr[i]--;
                        }
                        t >>= 1;
                    }
                    l++;
                }
                else
                {
                    break;
                }
            }

            r++;
            ans = max(ans, r - l);
        }
        return ans;
    }
};
