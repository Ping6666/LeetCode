#include <vector>
#include <algorithm>
#include <iostream>
using std::vector, std::sort;

// Runtime: 176 ms (Beats 100.00 %), Memory: 115.98 MB (Beats 98.28 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<int> idx_count(n, 0);

        for (int i = 0; i < roads.size(); i++)
        {
            idx_count[roads[i][0]]++, idx_count[roads[i][1]]++;
        }

        sort(idx_count.begin(), idx_count.end());

        long long ans = 0;
        for (long long i = 0; i < n; i++)
        {
            ans += (i + 1) * idx_count[i];
        }

        return ans;
    }
};
