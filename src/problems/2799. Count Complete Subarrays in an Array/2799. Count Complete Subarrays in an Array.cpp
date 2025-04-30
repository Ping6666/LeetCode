#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 36.17 MB (Beats 99.73 %).

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        const int n = nums.size();

        int count = 0;
        int num_freq[2000] = {0};
        for (const int num : nums)
        {
            if (num_freq[num - 1] == 0)
            {
                count++;
            }
            num_freq[num - 1]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int _count = 0;
            int _num_freq[2000] = {0};

            int j = i;
            for (; j < n; j++)
            {
                if (_num_freq[nums[j] - 1] == 0)
                {
                    _count++;
                }
                if (_count == count)
                {
                    break;
                }
                _num_freq[nums[j] - 1]++;
            }
            ans += n - j;

            num_freq[nums[i] - 1]--;
            if (num_freq[nums[i] - 1] == 0)
            {
                break;
            }
        }
        return ans;
    }
};
