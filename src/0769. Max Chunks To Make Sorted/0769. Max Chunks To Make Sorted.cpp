#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 9.10 MB (Beats 42.82 %).

// ref: LeetCode Editorial - Approach 4: Maximum Element

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();

        int ans = 0, _max = 0;

        for (int i = 0; i < n; i++)
        {
            _max = max(_max, arr[i]);

            if (_max == i)
            {
                ans++;
            }
        }

        return ans;
    }
};
