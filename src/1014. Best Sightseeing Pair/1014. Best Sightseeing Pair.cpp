#include <vector>
#include <queue>
using std::vector, std::max;

// Runtime: 0 ms (Beats 100.00 %), Memory: 45.52 MB (Beats 55.58 %).

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int max_front = values[0];
        int ans = 0;

        for (int i = 1; i < values.size(); i++)
        {
            ans = max(ans, max_front + values[i] - i);
            max_front = max(values[i] + i, max_front);
        }

        return ans;
    }
};
