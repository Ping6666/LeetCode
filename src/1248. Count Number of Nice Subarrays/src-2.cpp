#include <vector>
#include <iostream>
using std::vector;

// Runtime: 48 ms (Beats 99.36 %), Memory: 69.89 MB (Beats 91.54 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0, counter = 0;

        // last_but_k : last k     odd num from the perspective of curr. idx (may including curr. idx when k == 1)
        // last_but_k1: last k - 1 odd num in the perspective of curr. idx
        int last_but_k = 0, last_but_k1 = -1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2)
            {
                counter++;

                /* method 1: start */
                if (counter == 1)
                {
                    last_but_k = i;
                }
                else if (counter > k)
                {
                    last_but_k1 = last_but_k;

                    last_but_k++;
                    while (!(nums[last_but_k] % 2))
                    {
                        last_but_k++;
                    }

                    counter--;
                }
                /* method 1: end */
            }

            /* method 2: start */
            // while ((counter > k) || (!(nums[last_but_k] % 2) && (last_but_k < i)))
            // {
            //     if (nums[last_but_k] % 2)
            //     {
            //         last_but_k1 = last_but_k;
            //         counter--;
            //     }

            //     last_but_k++;
            // }
            /* method 2: end */

            if (counter == k)
            {
                // printf("%d %d\n", last_but_k, last_but_k1);
                ans += (last_but_k - last_but_k1);
            }
        }

        return ans;
    }
};
