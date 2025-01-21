#include <vector>
#include <queue>
using std::vector, std::priority_queue, std::pair, std::greater;

// Runtime: 0 ms (Beats 100.00 %), Memory: 27.58 MB (Beats 31.84 %).

class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }

        int tmp;
        for (int i = 0; i < k; i++)
        {
            auto t = pq.top();
            pq.pop();

            tmp = t.first * multiplier;
            nums[t.second] = tmp;
            pq.push({tmp, t.second});
        }

        return nums;
    }
};
