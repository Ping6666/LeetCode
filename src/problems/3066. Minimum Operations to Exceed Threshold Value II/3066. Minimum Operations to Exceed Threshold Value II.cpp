#include <vector>
#include <queue>
using std::vector, std::priority_queue, std::greater, std::min, std::max;

// Runtime: 89 ms (Beats 83.29 %), Memory: 92.32 MB (Beats 71.62 %).

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto &n : nums)
        {
            pq.push(n);
        }

        int ans = 0;
        int a, b;
        while (!pq.empty() && pq.top() < k)
        {
            a = min(pq.top(), k);
            pq.pop();
            b = min(pq.top(), k);
            pq.pop();

            pq.push(min(min(min(a, b) * 2, k) + max(a, b), k));

            ans++;
        }

        return ans;
    }
};
