#include <stdio.h>

#include <vector>
#include <algorithm> // sort

using namespace std;

bool sorter(const vector<int> &a, const vector<int> &b)
{
    // content in vector is [startDay, endDay, value]

    if (a[0] != b[0])
    {
        return a[0] < b[0];
    }
    else if (a[1] != b[1])
    {
        return a[1] < b[1];
    }

    return a[2] < b[2];
}

class Solution
{
    // Runtime: 305 ms (Beats 87.68 %), Memory: 72.7 MB (Beats 71.72 %).

private:
    /**
     * @param curr_idx: current event idx
     * @param curr_k: current maximum number of events can attend
     */
    int solveValues(vector<vector<int>> &sorted_events, vector<vector<int>> &values, int prev_end, int curr_idx, int curr_k)
    {
        if (curr_k <= 0 || curr_idx >= sorted_events.size())
        {
            // if any cond. happened return 0
            //   1. can not attend any more event
            //   2. there is no more event

            return 0;
        }

        if (sorted_events[curr_idx][0] <= prev_end)
        {
            // if can not take this event then check next event

            return solveValues(sorted_events, values, prev_end, curr_idx + 1, curr_k);
        }

        if (values[curr_idx][curr_k] != -1)
        {
            // if solve then return

            return values[curr_idx][curr_k];
        }

        int next_end = sorted_events[curr_idx][1];
        int curr_value = sorted_events[curr_idx][2];

        values[curr_idx][curr_k] = max(solveValues(sorted_events, values, prev_end, curr_idx + 1, curr_k),
                                       curr_value + solveValues(sorted_events, values, next_end, curr_idx + 1, curr_k - 1));

        return values[curr_idx][curr_k];
    }

public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        int n = events.size();

        sort(events.begin(), events.end(), sorter);

        vector<vector<int>> values(n, vector<int>(k + 1, -1));
        // n     : for number of events
        // k + 1 : for combination of events can attendance
        // -1    : for default unsolve value

        int prev_end = -1;
        // have not taken any event yet

        return solveValues(events, values, prev_end, 0, k);
    }
};

int main()
{
    int k;
    vector<vector<int>> events;

    int value;
    Solution s;

    k = 2;
    events = {{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};

    s = Solution();
    value = s.maxValue(events, k);
    printf("%d\n", value);

    k = 1;
    events = {{1, 2, 4}, {3, 4, 3}, {2, 3, 10}};

    s = Solution();
    value = s.maxValue(events, k);
    printf("%d\n", value);

    k = 3;
    events = {{1, 1, 4}, {2, 2, 2}, {3, 3, 3}, {4, 4, 1}};

    s = Solution();
    value = s.maxValue(events, k);
    printf("%d\n", value);

    return 0;
}
