#include <string>
using std::string;

// Runtime: 95 ms (Beats 87.14 %), Memory: 32.58 MB (Beats 91.34 %).

class Solution
{
public:
    int minSwaps(string s)
    {
        int left_count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
            {
                left_count++;
            }
            else
            {
                if (left_count > 0)
                {
                    left_count--;
                }
            }
        }

        return (left_count + 1) / 2;
    }
};
