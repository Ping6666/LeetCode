#include <math.h>
#include <vector>
using namespace std;

class Solution
{
    // Runtime: 32 ms (97.53 %), Memory: 25.8 MB (87.95 %).
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int maxDuration = 0;
        for (int i = 0; i < timeSeries.size() - 1; i++)
        {
            maxDuration += min(duration, timeSeries[i + 1] - timeSeries[i]);
        }
        // need to plus another duration when get last poison attack
        return maxDuration + duration;
    }
};
