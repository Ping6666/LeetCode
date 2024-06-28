#include <vector>
#include <queue>
using std::vector, std::deque, std::max;

// Runtime: 54 ms (Beats 95.78 %), Memory: 54.46 MB (Beats 81.10 %).

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();
        deque<int> max_deque, min_deque;

        int l = 0, r = 0;
        int ans = 0;
        while (r < n)
        {
            // keep track the values (max, min) in the range of (l, r)
            while (!max_deque.empty() && nums[r] > max_deque.back())
            {
                max_deque.pop_back();
            }
            max_deque.push_back(nums[r]);

            while (!min_deque.empty() && nums[r] < min_deque.back())
            {
                min_deque.pop_back();
            }
            min_deque.push_back(nums[r]);

            // adjust the range
            while (max_deque.front() - min_deque.front() > limit)
            {
                if (max_deque.front() == nums[l])
                {
                    max_deque.pop_front();
                }
                if (min_deque.front() == nums[l])
                {
                    min_deque.pop_front();
                }
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
