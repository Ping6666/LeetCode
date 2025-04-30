#include <vector>
using std::vector, std::min, std::max;

// Runtime: 0 ms (Beats 100.00 %), Memory: 112.42 MB (Beats 97.58 %).

class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        long long _curr, _min, _max;
        _curr = _min = _max = 0;

        for (const auto diff : differences)
        {
            _curr += diff;

            _min = min(_min, _curr);
            _max = max(_max, _curr);
        }

        // printf("%lld %lld\n", _min, _max);
        _max += (long long)lower - _min;
        // printf("%lld %d\n", _max, (int)_max);

        if (_max > (long long)upper)
        {
            return 0;
        }

        return upper - (int)_max + 1;
    }
};
