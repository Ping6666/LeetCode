#include <vector>
#include <limits.h>
using std::vector;

// Runtime: 60 ms (Beats 61.54 %), Memory: 88.10 MB (Beats 89.97 %).

class Solution
{
private:
    void newNum(vector<int> &bit_counts, int num, int step)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((num >> i) % 2 == 1)
            {
                bit_counts[i] += step;
            }
        }
    }

    int getNum(vector<int> &bit_counts)
    {
        int ans = 0;

        for (int i = 0; i < 32; i++)
        {
            if (bit_counts[i] != 0)
            {
                ans += 1 << i;
            }
        }

        return ans;
    }

public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int min_len = INT_MAX;
        int start = 0, end = 0;

        vector<int> bit_counts(32, 0);

        while (end < nums.size())
        {
            newNum(bit_counts, nums[end], 1);

            while (start <= end && getNum(bit_counts) >= k)
            {
                newNum(bit_counts, nums[start], -1);

                min_len = min(min_len, end - start + 1);
                start++;
            }

            end++;
        }

        return min_len == INT_MAX ? -1 : min_len;
    }
};
