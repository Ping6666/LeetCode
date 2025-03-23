#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 87 ms (Beats 73.71 %), Memory: 27.21 MB (Beats 31.24 %).

class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> vec;

        int sum;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                vec.push_back(sum);
            }
        }

        sort(vec.begin(), vec.end());

        int ans = 0, mod = 1e9 + 7;
        for (int i = left - 1; i <= right - 1; i++)
        {
            ans = (ans + vec[i]) % mod;
        }

        return ans;
    }
};
