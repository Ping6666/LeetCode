#include <vector>
#include <queue>
#include <unordered_set>
using std::vector, std::priority_queue, std::unordered_set, std::pair, std::greater;

// WA

class Solution
{
public:
    int minCapability(vector<int> &nums, int k)
    {
        const int n = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }

        int i = 0, ans = -1;
        unordered_set<int> _id;
        while (true)
        {
            auto t = pq.top();
            pq.pop();

            // printf("%d %d\n", t.first, t.second);

            if (_id.find(t.second + 1) == _id.end() &&
                _id.find(t.second - 1) == _id.end())
            {
                // no hit
                _id.insert(t.second);
                i++;

                if (i == k)
                {
                    return t.first;
                }
            }
            // else
            // {
            //     printf("%d\n", t.first);
            // }
        }
        return -1;
    }
};
