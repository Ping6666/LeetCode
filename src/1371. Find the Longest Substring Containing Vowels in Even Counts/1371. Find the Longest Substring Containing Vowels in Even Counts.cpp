#include <string>
#include <vector>
using std::string, std::vector, std::max;

// Runtime: 37 ms (Beats 80.70 %), Memory: 17.42 MB (Beats 88.84 %).

class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int char_map[26] = {0};
        char_map['a' - 'a'] = 1;
        char_map['e' - 'a'] = 2;
        char_map['i' - 'a'] = 4;
        char_map['o' - 'a'] = 8;
        char_map['u' - 'a'] = 16;

        int _xor = 0;
        vector<int> _map(32, -1);
        int ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            _xor ^= char_map[s[i] - 'a'];

            if (_xor != 0 && _map[_xor] == -1)
            {
                _map[_xor] = i;
            }

            ans = max(ans, i - _map[_xor]);
        }

        return ans;
    }
};
