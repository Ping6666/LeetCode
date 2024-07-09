#include <vector>
using std::vector;

// Runtime: 127 ms (Beats 97.65 %), Memory: 76.42 MB (Beats 83.82 %).

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double avg_wait = 0, n = customers.size();

        int curr_time = -1;
        for (const auto &customer : customers)
        {
            // arrival = customer[0];
            // time = customer[1];

            if (curr_time == -1 || curr_time < customer[0])
            {
                curr_time = customer[0];
            }
            curr_time += customer[1];

            avg_wait += (curr_time - customer[0]) / n;
        }

        return avg_wait;
    }
};
