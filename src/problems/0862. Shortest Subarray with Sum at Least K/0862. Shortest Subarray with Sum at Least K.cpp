#include <limits.h>
#include <vector>
#include <queue>
using std::vector, std::deque, std::min;

// Runtime: 29 ms (Beats 86.59 %), Memory: 107.47 MB (Beats 94.04 %).
// ref. LeetCode Editorial - Approach 3: Deque

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        deque<int> indices;

        int ans = INT_MAX;

        for (int i = 0; i <= n; i++)
        {
            while (!indices.empty() && prefix[i] - prefix[indices.front()] >= k)
            {
                ans = min(ans, i - indices.front());
                indices.pop_front();
            }

            while (!indices.empty() && prefix[i] <= prefix[indices.back()])
            {
                indices.pop_back();
            }

            indices.push_back(i);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

/*
class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = 0, sum = 0;
        int ans = INT_MAX;

        while (r < n)
        {
            sum += nums[r];

            while (l < r && sum >= k)
            {
                if ((sum - nums[l]) >= k)
                {
                    sum -= nums[l++];
                    printf("%d %d\n", l, r);
                }
                else
                {
                    break;
                }
            }

            if (sum >= k)
            {
                ans = min(ans, r - l + 1);
            }

            r++;
        }

        if (ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};
*/
