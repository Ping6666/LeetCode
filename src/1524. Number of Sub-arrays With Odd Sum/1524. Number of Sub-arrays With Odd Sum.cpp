#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 111.85 MB (Beats 96.38 %).

// find the pattern (math) & prefix sum

// [5,4,4,5,1,3]
// 0 0
// 1 1 1 2 1 2
// 1 1 1 3 2 4

// [100,100,99,99]
// 0 0
// 2 2 1 2
// 0 0 3 1

// [64,69,7,78,31,83,47,84,47,6,67]
// 0     0       0   0
// 2 1 2 2 1 2 1 1 2 2 1
// 0 2 1 1 4 2 5 5 4 4 7

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        const int _mod = 1e9 + 7;

        int ans = 0;
        int prev1 = 0, prev1_idx = -1;
        int prev2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 1)
            {
                // odd

                int curr = prev2 + (i - prev1_idx);
                ans += curr;
                ans %= _mod;

                prev2 = prev1;
                prev1 = curr;
                prev1_idx = i;
            }
            else
            {
                // even
                ans += prev1;
                ans %= _mod;
            }
        }

        return ans;
    }
};
