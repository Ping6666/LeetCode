#include <string>
#include <cmath>
using std::string, std::to_string, std::pow;

// Runtime: 0 ms (Beats 100.00 %), Memory: 10.16 MB (Beats 53.22 %).

class Solution
{
private:
    /**
     * return the num of powerful integer [1..src]
     */
    long long compute(const string &src, const string &s, const int limit)
    {
        if (src.length() < s.length())
        {
            // can not fit any powerful integer
            return 0;
        }
        else if (src.length() == s.length())
        {
            return src >= s ? 1 : 0;
        }

        long long ans = 0;
        int _len = src.length() - s.length();
        for (int i = 0; i < _len; i++)
        {
            int _count = src[i] - '0';
            if (limit < _count)
            {
                // can have all after
                ans += pow(limit + 1, _len - i);
                return ans;
            }
            ans += (long)_count * pow(limit + 1, _len - 1 - i);
        }
        string suffix = src.substr(_len, s.length());
        if (suffix >= s)
        {
            // got another
            ans++;
        }
        return ans;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish,
                                  int limit, string s)
    {
        return compute(to_string(finish), s, limit) - compute(to_string(start - 1), s, limit);
    }
};
