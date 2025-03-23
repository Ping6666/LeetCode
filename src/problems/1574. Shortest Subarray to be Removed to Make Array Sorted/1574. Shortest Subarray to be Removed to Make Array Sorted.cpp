#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 69.36 MB (Beats 98.14 %).

class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int r = n - 1;
        while (r > 0 && arr[r] >= arr[r - 1])
        {
            r--;
        }

        int ans = r;
        int l = 0;

        while (l < r && (l == 0 || (arr[l - 1] <= arr[l])))
        {
            while (r < n && arr[l] > arr[r])
            {
                r++;
            }

            ans = min(ans, r - l - 1);
            l++;
        }

        return ans;
    }
};
