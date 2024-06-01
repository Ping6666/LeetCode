#include <string>

class Solution
{
    // Runtime: 0 ms (100.00 %), Memory: 7.31 MB (93.86 %).

public:
    int numSteps(std::string s)
    {
        int l = s.size();

        int _add = 0;
        int _mul = l - 1;

        bool carry = false;

        // no need to consider front '1' (always be '1')
        for (int i = l - 1; i >= 1; i--)
        {
            if (!carry && s[i] == '1')
            {
                _add += 1;
                carry = true;
            }
            else if (carry && s[i] == '0')
            {
                _add += 1;
            }
        }

        if (carry)
        {
            // still remain a '1' at front
            _mul += 1;
        }

        return _mul + _add;
    }
};
