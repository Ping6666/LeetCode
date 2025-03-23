#include <string>
#include <unordered_set>
using std::string, std::unordered_set;

// Runtime: 151 ms (Beats 77.00 %), Memory: 16.08 MB (Beats 47.85 %).

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int freq_r[26] = {0};
        int freq_l[26] = {0};

        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            freq_r[s[i] - 'a']++;
        }

        freq_l[s[0] - 'a']++;
        freq_r[s[0] - 'a']--;

        unordered_set<int> _set;

        int _curr, _tmp;
        for (int i = 1; i < n - 1; i++)
        {
            _curr = s[i] - 'a';
            freq_r[_curr]--;

            for (int j = 0; j < 26; j++)
            {
                if (freq_l[j] > 0 && freq_r[j] > 0)
                {
                    _tmp = j * 26 + _curr;
                    _set.insert(_tmp);
                }
            }

            freq_l[_curr]++;
        }
        return _set.size();
    }
};
