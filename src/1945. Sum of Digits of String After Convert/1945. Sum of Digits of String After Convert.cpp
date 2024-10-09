#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.70 MB (Beats 97.87 %).

class Solution
{
public:
    int getLucky(string s, int k)
    {
        int _sum = 0, p;
        for (const auto &c : s)
        {
            p = c - 'a' + 1;
            if (p < 10)
            {
                _sum += p;
            }
            else
            {
                _sum += p / 10;
                _sum += p % 10;
            }
        }
        k--;

        int ans = _sum;
        while (k > 0)
        {
            ans = 0;
            while (_sum > 0)
            {
                ans += _sum % 10;
                _sum /= 10;
            }
            _sum = ans;
            k--;
        }

        return ans;
    }
};
