#include <vector>
#include <queue>
#include <set>
#include <map>
using std::vector, std::priority_queue, std::set, std::map;

// Runtime: 306 ms (Beats 13.75 %), Memory: 110.60 MB (Beats 6.19 %).

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        priority_queue<int, vector<int>, std::greater<int>> seats_pool;
        set<int> times_set;
        map<int, vector<int>> arrival_table;
        map<int, vector<int>> leaving_table;

        int n = times.size();
        vector<int> assigned_seats(n, -1);

        int curr_max_seats = 0;

        for (int i = 0; i < n; i++)
        {
            times_set.insert(times[i][0]);
            times_set.insert(times[i][1]);

            arrival_table[times[i][0]].push_back(i);
            leaving_table[times[i][1]].push_back(i);
        }

        for (const auto &t : times_set)
        {
            // leaving
            if (leaving_table.find(t) != leaving_table.end())
            {
                for (const auto &l : leaving_table[t])
                {
                    seats_pool.push(assigned_seats[l]);
                }
            }

            // arrival
            if (arrival_table.find(t) != arrival_table.end())
            {
                for (const auto &a : arrival_table[t])
                {
                    int tgt_seat;
                    if (!seats_pool.empty())
                    {
                        tgt_seat = seats_pool.top();
                        seats_pool.pop();
                    }
                    else
                    {
                        tgt_seat = curr_max_seats++;
                    }

                    if (a == targetFriend)
                    {
                        return tgt_seat;
                    }

                    assigned_seats[a] = tgt_seat;
                }
            }
        }

        return -1;
    }
};
