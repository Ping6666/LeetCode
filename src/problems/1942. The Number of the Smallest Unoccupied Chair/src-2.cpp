#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using std::vector, std::priority_queue, std::set, std::sort;

// Runtime: 108 ms (Beats 99.66 %), Memory: 54.72 MB (Beats 97.59 %).

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        // pair<int, int>(time, seat idx)
        priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> seated;

        int tgt_time = times[targetFriend][0];
        sort(times.begin(), times.end());

        int next_seats = 0;
        priority_queue<int, vector<int>, std::greater<int>> seats_pool;

        for (const auto &t : times)
        {
            // leaving
            while (!seated.empty() && seated.top().first <= t[0])
            {
                seats_pool.push(seated.top().second);
                seated.pop();
            }

            // arrival
            int tgt_seat;
            if (!seats_pool.empty())
            {
                tgt_seat = seats_pool.top();
                seats_pool.pop();
            }
            else
            {
                tgt_seat = next_seats++;
            }

            if (t[0] == tgt_time)
            {
                return tgt_seat;
            }

            seated.emplace(t[1], tgt_seat);
        }

        return -1;
    }
};
