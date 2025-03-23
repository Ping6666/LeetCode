#include <vector>
#include <queue>
using std::vector, std::priority_queue, std::pair;

// Runtime: 108 ms (Beats 75.45 %), Memory: 105.52 MB (Beats 69.61 %).

class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        int n = nums.size();

        vector<bool> marked_idx(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }

        long long ans = 0;

        while (!pq.empty())
        {
            auto t = pq.top();
            pq.pop();

            if (marked_idx[t.second])
            {
                // found the marked index
                continue;
            }

            ans += t.first;

            if (t.second != 0)
            {
                marked_idx[t.second - 1] = true;
            }
            marked_idx[t.second] = true;
            if (t.second != n - 1)
            {
                marked_idx[t.second + 1] = true;
            }
        }

        return ans;
    }
};
