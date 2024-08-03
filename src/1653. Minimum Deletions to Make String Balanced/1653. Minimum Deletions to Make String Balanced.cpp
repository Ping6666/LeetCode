#include <string>
using std::string;

// Runtime: 76 ms (Beats 89.95 %), Memory: 23.44 MB (Beats 80.38 %).

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size();

        int curr = 0;
        // int lb = 0, ra = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                curr++;
            }
        }

        int _min = curr;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'b')
            {
                curr++;
            }
            else
            {
                curr--;
            }

            if (curr < _min)
            {
                _min = curr;
            }
        }

        return _min;
    }
};
