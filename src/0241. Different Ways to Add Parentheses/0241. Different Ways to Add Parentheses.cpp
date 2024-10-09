#include <string>
#include <vector>
using std::string, std::vector, std::stoi;

// Runtime: 0 ms (Beats 100.00 %), Memory: 13.51 MB (Beats 61.78 %).

class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {

        int n = expression.size();
        if (n == 0)
        {
            return {};
        }
        else if ((n == 1) || (n == 2 && isdigit(expression[0])))
        {
            // [0, 99]
            return {stoi(expression)};
        }

        vector<int> ans;
        char _char;
        int _tmp;

        for (int i = 0; i < n; i++)
        {
            _char = expression[i];
            if (isdigit(_char))
            {
                continue;
            }

            vector<int> _left = diffWaysToCompute(expression.substr(0, i));
            vector<int> _right = diffWaysToCompute(expression.substr(i + 1));

            for (const auto &_l : _left)
            {
                for (const auto &_r : _right)
                {
                    if (_char == '+')
                    {
                        _tmp = _l + _r;
                    }
                    else if (_char == '-')
                    {
                        _tmp = _l - _r;
                    }
                    else if (_char == '*')
                    {
                        _tmp = _l * _r;
                    }

                    ans.push_back(_tmp);
                }
            }
        }

        return ans;
    }
};
