#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map;

// Runtime: 71 ms (Beats 91.94 %), Memory: 78.95 MB (Beats 93.36 %).

class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        const int n = nums.size();

        int l = 0, r = 0;
        long long count = 0;

        unordered_map<int, int> num_freq;

        long long ans = 0;
        while (l < n)
        {
            while (r < n && count < k)
            {
                // push nums[r]
                // for (int i = l; i < r; i++)
                // {
                //     if (nums[i] == nums[r])
                //     {
                //         count++;
                //     }
                // }
                if (num_freq.find(nums[r]) != num_freq.end())
                {
                    count += num_freq[nums[r]];
                }
                num_freq[nums[r]]++;

                r++;
            }

            if (r >= n && count < k)
            {
                break;
            }

            ans += (n - r) + 1;

            // pop nums[l]
            // for (int i = l + 1; i < r; i++)
            // {
            //     if (nums[i] == nums[l])
            //     {
            //         count--;
            //     }
            // }
            num_freq[nums[l]]--;
            count -= num_freq[nums[l]];

            l++;
        }
        return ans;
    }
};
