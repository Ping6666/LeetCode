#include <vector>
#include <string>
#include <queue>
using std::vector, std::string, std::priority_queue, std::greater;

// Runtime: 0 ms (Beats 100.00 %), Memory: 12.54 MB (Beats 84.00 %).

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();
        priority_queue<long, vector<long>, greater<long>> pq;
        for (const auto &num : nums)
        {
            long l = 0;
            for (const auto &c : num)
            {
                l *= 2;
                if (c == '1')
                {
                    l += 1;
                }
            }
            pq.push(l);
        }

        int v = 0;
        while (!pq.empty())
        {
            if (v == pq.top())
            {
                v++;
                pq.pop();
            }
            else
            {
                break;
            }
        }

        string ans = string(n, '0');
        int idx = 0;
        while (v > 0)
        {
            if (v % 2 == 1)
            {
                ans[n - idx - 1] = '1';
            }
            idx++;
            v /= 2;
        }
        return ans;
    }
};
