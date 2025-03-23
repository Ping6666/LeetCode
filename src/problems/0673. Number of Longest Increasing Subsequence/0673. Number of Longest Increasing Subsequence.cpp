#include <stdio.h>

#include <vector>

using namespace std;

void printVector(vector<pair<int, int>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i].first);
    }
    printf("\n");
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i].second);
    }
    printf("\n");
}

class Solution
{
    // Runtime: 158 ms (Beats 84.76 %), Memory: 13.1 MB (Beats 95.24 %).

public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<pair<int, int>> dp(n, pair<int, int>(0, 0));
        // the pair stand for the current max length & the number of LIS for current number in the nums

        pair<int, int> curr_dp;

        for (int i = 0; i < n; i++)
        {
            curr_dp = pair<int, int>(0, 0);
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    // follow below 1~2 condition
                    //   1. strictly increasing
                    //   2. longest

                    if (curr_dp.first < dp[j].first)
                    {
                        curr_dp.first = dp[j].first;
                        curr_dp.second = dp[j].second;
                    }
                    else if (curr_dp.first == dp[j].first)
                    {
                        // curr_dp.first = dp[j].first;
                        curr_dp.second += dp[j].second;
                    }
                }
            }

            curr_dp.first++;

            if (curr_dp.first == 1)
            {
                curr_dp.second += 1;
            }

            dp[i] = curr_dp;
        }

        printVector(dp);

        pair<int, int> max_dp(0, 0);

        for (int i = 0; i < n; i++)
        {
            if (dp[i].first > max_dp.first)
            {
                max_dp.first = dp[i].first;
                max_dp.second = dp[i].second;
            }
            else if (dp[i].first == max_dp.first)
            {
                max_dp.second += dp[i].second;
            }
        }

        return max_dp.second;
    }
};

int main()
{
    vector<int> nums;

    Solution s;
    int ans;

    nums = {1, 3, 5, 4, 7};
    s = Solution();
    ans = s.findNumberOfLIS(nums);
    printf("%d\n", ans);

    nums = {2, 2, 2, 2, 2};
    s = Solution();
    ans = s.findNumberOfLIS(nums);
    printf("%d\n", ans);

    nums = {1, 2, 4, 3, 5, 4, 7, 2};
    s = Solution();
    ans = s.findNumberOfLIS(nums);
    printf("%d\n", ans);

    return 0;
}
