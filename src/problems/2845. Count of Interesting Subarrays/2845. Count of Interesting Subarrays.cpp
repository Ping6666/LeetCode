#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map;

// Runtime: 61 ms (Beats 46.45 %), Memory: 122.85 MB (Beats 53.01 %).
// ref.: LeetCode Eidtorial - Approach: Prefix Sum

class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums,
                                        int modulo, int k)
    {
        const int n = nums.size();
        int prefix_count = 0;

        unordered_map<int, int> m;
        m[0] = 1; // important here

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % modulo == k)
            {
                // hit
                prefix_count++;
            }

            ans += m[(prefix_count + modulo - k) % modulo];
            m[prefix_count % modulo]++;
        }
        return ans;
    }
};
