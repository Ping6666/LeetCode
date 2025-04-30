#include <string>
#include <vector>
using std::string, std::to_string, std::vector;

// Runtime: 2 ms (Beats 89.33 %), Memory: 11.18 MB (Beats 22.35 %).

class Solution
{
public:
    string countAndSay(int n)
    {
        vector<int> _curr;
        _curr.push_back(1);

        vector<int> _prev;
        for (int i = 0; i < n - 1; i++)
        {
            _prev = vector(_curr);
            _curr.clear();

            int _idx = 0, count = 0;
            int _l = _prev.size();
            for (int j = 0; j < _l; j++)
            {
                if (_prev[_idx] == _prev[j])
                {
                    count++;
                }
                else
                {
                    // save
                    for (const auto &_n : to_string(count))
                    {
                        _curr.push_back(_n - '0');
                    }
                    _curr.push_back(_prev[_idx]);

                    // reset
                    _idx = j;
                    count = 1;
                }
            }

            // save last
            for (const auto &_n : to_string(count))
            {
                _curr.push_back(_n - '0');
            }
            _curr.push_back(_prev[_idx]);
        }

        string ans = "";
        for (const auto n : _curr)
        {
            ans += '0' + n;
        }
        return ans;
    }
};
