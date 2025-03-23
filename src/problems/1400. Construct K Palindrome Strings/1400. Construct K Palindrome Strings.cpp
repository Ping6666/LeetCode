#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 14.79 MB (Beats 78.67 %).

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        int n = s.size();
        if (n < k)
        {
            return false;
        }
        else if (n == k)
        {
            return true;
        }

        int freq[26] = {0};
        for (const auto &c : s)
        {
            freq[c - 'a']++;
        }

        int _odd = 0, _even = 0;
        for (int i = 0; i < 26; i++)
        {
            _even += freq[i] / 2;
            if (freq[i] % 2 == 1)
            {
                _odd++;
            }
        }

        if (_odd > k)
        {
            return false;
        }
        return true;
    }
};
