#include <limits.h>
#include <vector>
using std::vector, std::max;

// Runtime: 23 ms (Beats 26.83 %), Memory: 35.26 MB (Beats 16.53 %).

// ref.: LeetCode Editorial - Approach 1: Memoization

class Solution
{
private:
    int dp(const vector<int> &sums, const int &k,
           int idx, int remain, vector<vector<int>> &memo)
    {
        if (remain == 0)
        {
            return 0;
        }
        if (idx >= sums.size())
        {
            if (remain > 0)
            {
                return INT_MIN;
            }
            else
            {
                return 0;
            }
        }

        if (memo[idx][remain] != -1)
        {
            return memo[idx][remain];
        }

        int with_curr = sums[idx] + dp(sums, k, idx + k, remain - 1, memo);
        int skip_curr = dp(sums, k, idx + 1, remain, memo);

        memo[idx][remain] = max(with_curr, skip_curr);
        return memo[idx][remain];
    }

    void dfs(const vector<int> &sums, const int &k,
             int idx, int remain, vector<vector<int>> &memo,
             vector<int> &indices)
    {
        if (remain == 0)
        {
            return;
        }
        if (k >= sums.size())
        {
            return;
        }

        int with_curr = sums[idx] + dp(sums, k, idx + k, remain - 1, memo);
        int skip_curr = dp(sums, k, idx + 1, remain, memo);

        if (with_curr >= skip_curr)
        {
            indices.push_back(idx);
            dfs(sums, k, idx + k, remain - 1, memo, indices);
        }
        else
        {
            dfs(sums, k, idx + 1, remain, memo, indices);
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size() - k + 1;
        vector<int> sums(n, 0);
        int temp_sum = 0;

        for (int i = 0; i < k; i++)
        {
            temp_sum += nums[i];
        }
        sums[0] = temp_sum;

        for (int i = k; i < nums.size(); i++)
        {
            temp_sum = temp_sum - nums[i - k] + nums[i];
            sums[i - k + 1] = temp_sum;
        }

        vector<vector<int>> memo(n, vector<int>(4, -1));
        vector<int> indices;

        dp(sums, k, 0, 3, memo);
        dfs(sums, k, 0, 3, memo, indices);

        return indices;
    }
};
