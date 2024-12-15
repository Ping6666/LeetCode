#include <vector>
using std::vector;

// Runtime: 35 ms (Beats 88.33 %), Memory: 79.10 MB (Beats 77.72 %).

// ref LeetCode Editorial - Approach 3: Iterative Dynamic Programming (Bottom-Up)

class Solution
{
private:
    int shortestDistance(const int &n, vector<vector<int>> &table)
    {
        vector<int> dp(n);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            int _min = n;

            for (const auto &t : table[i])
            {
                _min = min(_min, dp[t] + 1);
            }
            dp[i] = _min;
        }

        return dp[0];
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> ans;
        vector<vector<int>> table(n, vector<int>(0));

        for (int i = 0; i < n - 1; i++)
        {
            table[i].push_back(i + 1);
        }

        for (const auto &q : queries)
        {
            table[q[0]].push_back(q[1]);

            ans.push_back(shortestDistance(n, table));
        }

        return ans;
    }
};
