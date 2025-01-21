#include <vector>
using std::vector;

// Runtime: 92 ms (Beats 91.77 %), Memory: 166.15 MB (Beats 94.94 %).
// ref: LeetCode Editorial - Approach 1: Depth-First-Search (DFS)

class Solution
{
private:
    int dfs(int _curr, int _prev,
            vector<int> *adj_list, vector<int> &values,
            const int &k, int &ans)
    {
        int sum = 0;

        for (const auto &_next : adj_list[_curr])
        {
            if (_next != _prev)
            {
                sum += dfs(_next, _curr, adj_list, values, k, ans);
                sum %= k;
            }
        }

        sum += values[_curr];
        sum %= k;

        if (sum == 0)
        {
            ans++;
        }

        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        vector<int> adj_list[n];

        for (const auto &e : edges)
        {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }

        int ans = 0;
        dfs(0, -1, adj_list, values, k, ans);
        return ans;
    }
};
