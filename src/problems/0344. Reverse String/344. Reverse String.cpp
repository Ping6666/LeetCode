#include <vector>
using std::vector;

class Solution
{
    // Runtime: 10 ms (Beats 95.59 %), Memory: 26.88 MB (Beats 89.96 %).

public:
    void reverseString(vector<char> &s)
    {
        // in-place with O(1) extra memory

        char c;

        int l = s.size();

        for (int i = 0; i < (l / 2); i++)
        {
            c = s[i];
            s[i] = s[l - i - 1];
            s[l - i - 1] = c;
        }
    }
};
