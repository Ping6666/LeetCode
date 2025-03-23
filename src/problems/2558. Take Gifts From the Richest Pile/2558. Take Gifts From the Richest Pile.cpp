#include <vector>
#include <queue>
#include <math.h>
using std::vector, std::priority_queue;

// Runtime: 0 ms (Beats 100.00 %), Memory: 12.92 MB (Beats 89.48 %).

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> pq;

        for (const auto &g : gifts)
        {
            pq.push(g);
        }

        int t;
        for (int i = 0; i < k; i++)
        {
            t = pq.top();

            if (t == 1)
            {
                break;
            }

            pq.pop();

            pq.push(floor(sqrt(t)));
        }

        long long ans = 0;
        while (!pq.empty())
        {
            t = pq.top();
            pq.pop();

            ans += t;
        }

        return ans;
    }
};
