#include <vector>
#include <map>
using std::vector, std::map;

// Runtime: 88 ms (Beats 87.13 %), Memory: 112.87 MB (Beats 87.68 %).

class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = 0;

        map<int, int> m;
        long long ans = 0;

        for (r = 0; r < n; r++)
        {
            m[nums[r]]++;

            while (m.rbegin()->first - m.begin()->first > 2)
            {
                m[nums[l]]--;
                if (m[nums[l]] == 0)
                {
                    m.erase(nums[l]);
                }
                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};
