#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.60 MB (Beats 83.69 %).

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
        {
            return false;
        }

        s = s + s;

        return s.find(goal) < s.size();
    }
};
