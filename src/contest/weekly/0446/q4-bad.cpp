#include <vector>
using std::vector;

// TLE (Time Limit Exceeded)
// 767 / 781 testcases passed

class Solution
{
private:
    int compute(const vector<int> &nums, const int idx, const int x, const int k)
    {
        const int n = nums.size();

        // dp
        vector<vector<long long>> count(n, vector<long long>(k, 0));
        count[idx][nums[idx]] += 1;

        for (int i = idx + 1; i < n; i++)
        {
            // fixed the perfix
            // count[i][nums[i]] += 1;

            for (int j = 0; j < k; j++)
            {
                long long ck = (j * nums[i]) % k;

                count[i][ck] += count[i - 1][j];
            }

            // for (int j = 0; j < k; j++)
            // {
            //     printf("%d ", count[i][j]);
            // }
            // printf("\n");
        }
        // printf("\n");

        vector<long long> ans(k, 0);
        for (int i = idx; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                ans[j] += count[i][j];
            }
        }
        return (int)ans[x];
    }

public:
    vector<int> resultArray(vector<int> &nums, int k, vector<vector<int>> &queries)
    {
        const int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            nums[i] %= k;
        }

        vector<int> ans;
        for (const auto query : queries)
        {
            nums[query[0]] = query[1] % k;
            ans.push_back(compute(nums, query[2], query[3], k));
        }

        return ans;
    }
};
