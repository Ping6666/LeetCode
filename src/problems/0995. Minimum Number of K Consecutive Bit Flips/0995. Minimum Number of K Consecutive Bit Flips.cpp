#include <vector>
#include <queue>
#include <iostream>
using std::vector, std::queue;

// Runtime: 52 ms (Beats 100.00 %), Memory: 110.36 MB (Beats 77.25 %).
// greedy, sliding window, queue

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        // flip all int in nums into 1

        int n = nums.size();

        bool flip_next = false;
        queue<int> flip_idx;

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (flip_idx.front() == i)
            {
                flip_next = !flip_next;
                flip_idx.pop();
            }

            if (flip_next == !(!(nums[i])))
            {
                if (i > n - k)
                {
                    return -1;
                }

                flip_next = !flip_next;
                flip_idx.push(i + k);

                ans++;
            }
        }

        return ans;
    }
};
