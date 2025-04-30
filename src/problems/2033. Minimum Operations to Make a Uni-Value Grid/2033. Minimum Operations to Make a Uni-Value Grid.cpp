#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 42 ms (Beats 57.75 %), Memory: 89.98 MB (Beats 62.01 %).

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        const int n = grid.size() * grid[0].size();
        vector<int> arr;
        for (const auto &g : grid)
        {
            for (auto &v : g)
            {
                arr.push_back(v);
            }
        }
        sort(arr.begin(), arr.end());

        int pivot = arr[n / 2];
        int d, s; // diff, step

        int ans = 0;
        for (const auto &g : grid)
        {
            for (auto &v : g)
            {
                d = v - pivot;
                s = d / x;

                if (s * x != d)
                {
                    return -1;
                }

                ans += abs(s);
            }
        }
        return ans;
    }
};
