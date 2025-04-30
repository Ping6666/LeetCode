#include <vector>
#include <cmath>
using std::vector, std::floor, std::min, std::max;

class Solution
{
private:
    long long getMinOperation(const int l, const int r)
    {
        int _base = 1;

        long long ans = 0;
        for (int p = 1; p < 16; p++)
        {
            _base *= 4;

            int lll = max(l, _base / 4);
            int rrr = min(r, _base - 1);

            if (_base / 4 > r)
            {
                break;
            }

            if (lll <= rrr)
            {
                ans += p * (long long)(rrr - lll + 1);
            }
        }

        return (ans + 1) / 2;
    }

public:
    long long minOperations(vector<vector<int>> &queries)
    {
        long long ans = 0;
        for (const auto &q : queries)
        {
            ans += getMinOperation(q[0], q[1]);
        }
        return ans;
    }
};
