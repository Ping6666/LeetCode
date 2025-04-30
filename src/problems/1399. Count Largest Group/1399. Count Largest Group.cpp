#include <unordered_map>
using std::unordered_map;

// Runtime: 0 ms (Beats 100.00 %), Memory: 8.08 MB (Beats 57.97 %).

int get_sum(int n)
{
    int _sum = 0;
    while (n > 0)
    {
        _sum += n % 10;
        n /= 10;
    }
    return _sum;
}

class Solution
{
public:
    int countLargestGroup(int n)
    {
        int _max = 0;
        unordered_map<int, int> m;
        for (int i = 1, _sum; i <= n; i++)
        {
            _sum = get_sum(i);
            m[_sum]++;

            if (m[_sum] > _max)
            {
                _max = m[_sum];
            }
        }

        int ans = 0;
        for (auto _m : m)
        {
            if (_m.second == _max)
            {
                ans++;
            }
        }
        return ans;
    }
};
