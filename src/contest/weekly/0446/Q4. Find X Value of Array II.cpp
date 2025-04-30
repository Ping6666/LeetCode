#include <vector>
using std::vector;

// TLE (Time Limit Exceeded)
// 774 / 781 testcases passed

class Solution
{
private:
    int compute(const vector<int> &nums, const int idx, const int x, const int k)
    {
        const int n = nums.size();

        // dp
        vector<int> _tmp(k, 0), count(k, 0);
        count[nums[idx]] += 1;

        int ans = count[x];

        for (int i = idx + 1; i < n; i++)
        {
            // fixed the perfix
            // count[nums[i]] += 1;

            for (int j = 0; j < k; j++)
            {
                if (count[j] == 0)
                {
                    continue;
                }

                _tmp[(j * nums[i]) % k] += count[j];
            }
            for (int j = 0; j < k; j++)
            {
                count[j] = _tmp[j];
                _tmp[j] = 0;
            }

            // for (int j = 0; j < k; j++)
            // {
            //     printf("%d ", count[i][j]);
            // }
            // printf("\n");

            ans += count[x];
        }
        // printf("\n");

        return ans;
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
