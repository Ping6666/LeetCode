#include <vector>
#include <queue>
using std::vector, std::queue, std::max;

// Runtime: 8 ms (Beats 98.77 %), Memory: 93.02 MB (Beats 90.16 %).

class Solution
{
public:
    int maximumInvitations(vector<int> &favorite)
    {
        int n = favorite.size();

        vector<int> in_degree(n, 0);

        for (const auto &f : favorite)
        {
            in_degree[f]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> depth(n, 1);
        while (!q.empty())
        {
            int _curr = q.front();
            q.pop();

            int _next = favorite[_curr];
            depth[_next] = max(depth[_next], depth[_curr] + 1);

            if (--in_degree[_next] == 0)
            {
                q.push(_next);
            }
        }

        // at this point in_degree all be 0 or 1

        int longest_cycle = 0;
        int two_cycle_sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (in_degree[i] == 0)
            {
                // visited
                continue;
            }

            int cycle_len = 0;
            int _curr = i;

            while (in_degree[_curr] != 0)
            {
                in_degree[_curr]--;

                cycle_len++;
                _curr = favorite[_curr];
            }

            if (cycle_len == 2)
            {
                two_cycle_sum += depth[i] + depth[favorite[i]];
            }
            else
            {
                longest_cycle = max(longest_cycle, cycle_len);
            }
        }

        return max(longest_cycle, two_cycle_sum);
    }
};
