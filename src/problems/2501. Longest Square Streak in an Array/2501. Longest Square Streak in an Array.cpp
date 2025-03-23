#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>
using std::vector, std::unordered_map, std::unordered_set, std::sort, std::sqrt;

// Runtime: 259 ms (Beats 6.67 %), Memory: 212.94 MB (Beats 6.43 %).

int getMinSqrt(int v)
{
    // NOTE can speed up by compute the square layer

    // get int will get floor
    int _r = (int)sqrt(v);

    if (_r * _r != v)
    {
        // v is not an square number
        return -1;
    }

    int __r = _r;
    do
    {
        _r = __r;
        __r = (int)sqrt(_r);
    } while (__r * __r == _r);

    return _r;
}

class Solution
{

public:
    int longestSquareStreak(vector<int> &nums)
    {
        unordered_map<int, unordered_set<int>> table;

        int r;
        for (const auto &n : nums)
        {
            r = getMinSqrt(n);

            if (r == -1)
            {
                r = n;
            }
            table[r].insert(n);
        }

        int ans = -1;

        vector<int> v;
        for (const auto &t : table)
        {
            if (t.second.size() < 2)
            {
                continue;
            }

            v.clear();
            for (const auto &n : t.second)
            {
                v.push_back(n);
            }
            sort(v.begin(), v.end());

            int c_max = 1;
            int _prev = v[0];

            for (int i = 1; i < v.size() && _prev <= 320; i++)
            {
                // some cheat 100000 sqrt < 320

                if (v[i] == _prev * _prev)
                {
                    c_max++;

                    ans = max(ans, c_max);
                }
                else
                {
                    c_max = 1;
                }
                _prev = v[i];
            }

            // printf("%d: ", t.first);
            // for (int i = 0; i < v.size() && i <= 5; i++)
            // {
            //     printf("%d ", v[i]);
            // }
            // printf("\n");
        }

        return ans;
    }
};
