#include <queue>
#include <vector>
using std::vector, std::queue, std::pair;

class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    vector<int> baseUnitConversions(vector<vector<int>> &conversions)
    {
        const int n = conversions.size() + 1;
        vector<vector<pair<int, int>>> adj(n);

        for (const auto &conversion : conversions)
        {
            adj[conversion[0]].push_back({conversion[1], conversion[2]});
        }

        queue<int> q;
        q.push(0);

        vector<int> ans(n, 0);
        ans[0] = 1;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            for (const auto _next : adj[f])
            {
                ans[_next.first] = (int)(((long long)ans[f] * _next.second) % MOD);
                q.push(_next.first);
            }
        }
        return ans;
    }
};
