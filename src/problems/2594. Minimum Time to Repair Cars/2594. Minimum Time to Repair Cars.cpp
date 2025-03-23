#include <vector>
#include <cmath>
using std::vector, std::sqrt, std::floor;

// Runtime: 19 ms (Beats 87.19 %), Memory: 59.27 MB (Beats 74.95 %).

class Solution
{
public:
    long long repairCars(vector<int> &ranks, int cars)
    {
        const int n = ranks.size();
        long long l = 1, r = 100 * (((long long)cars / n) + 1) * (((long long)cars / n) + 1) + 1;
        long long m, ans = r;
        int _cars;

        while (l < r)
        {
            m = l + (r - l) / 2;
            // printf("\n\n#: %d\n", m);

            _cars = 0;
            for (int i = 0; i < n && _cars <= cars; i++)
            {
                // printf("%d %d %d\n", i, ranks[i], int(floor(sqrt(m / ranks[i]))));
                _cars += int(floor(sqrt(m / ranks[i])));
            }

            if (_cars >= cars)
            {
                // can fit
                r = m;
                ans = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return ans;
    }
};
