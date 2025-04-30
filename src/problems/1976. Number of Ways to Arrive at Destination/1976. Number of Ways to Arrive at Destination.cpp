#include <limits.h>
#include <vector>
#include <queue>
using std::vector, std::priority_queue, std::pair, std::greater;

// Runtime: 10 ms (Beats 57.15 %), Memory: 37.22 MB (Beats 56.38 %).

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        const int _mod = 1e9 + 7;

        vector<vector<pair<int, int>>> graph(n);
        for (const auto r : roads)
        {
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }

        // time, node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        vector<long long> shortest_time(n, LLONG_MAX);
        vector<int> shortest_count(n, 0);

        shortest_time[0] = 0;
        shortest_count[0] = 1;

        pq.push({0, 0});
        while (!pq.empty())
        {
            auto t = pq.top();
            pq.pop();

            long long _time = t.first;
            int _curr = t.second;

            // if not up-to-date
            if (shortest_time[_curr] < _time)
            {
                continue;
            }

            for (const auto g : graph[_curr])
            {
                int _next = g.first;
                long long _new_time = _time + g.second;

                if (_new_time < shortest_time[_next])
                {
                    shortest_time[_next] = _new_time;
                    shortest_count[_next] = shortest_count[_curr];

                    pq.push({_new_time, _next});
                }
                else if (_new_time == shortest_time[_next])
                {
                    shortest_count[_next] = (shortest_count[_next] + shortest_count[_curr]) % _mod;
                }
            }
        }
        return shortest_count[n - 1];
    }
};
