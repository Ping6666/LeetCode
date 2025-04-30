#include <vector>
#include <queue>
using std::vector, std::priority_queue;

class Solution
{
public:
    int maximumPossibleSize(vector<int> &nums)
    {
        priority_queue<int> pq;
        for (const auto num : nums)
        {
            if (pq.empty())
            {
                pq.push(num);
            }
            else
            {
                auto t = pq.top();

                if (t > num)
                {
                    continue;
                }

                pq.push(num);
            }
        }
        return pq.size();
    }
};
