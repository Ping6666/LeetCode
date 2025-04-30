#include <vector>
using std::vector;

class Solution
{
private:
    vector<long long> compute(const vector<int> &nums, const int k)
    {
        const int n = nums.size();

        // dp
        vector<vector<long long>> count(n, vector<long long>(k, 0));
        count[0][nums[0]] += 1;

        for (int i = 1; i < n; i++)
        {
            count[i][nums[i]] += 1;
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

        vector<long long> ans(k, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                ans[j] += count[i][j];
            }
        }
        return ans;
    }

public:
    vector<long long> resultArray(vector<int> &nums, int k)
    {
        const int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            nums[i] %= k;
        }

        return compute(nums, k);
    }
};
