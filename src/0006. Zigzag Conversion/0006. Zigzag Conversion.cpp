#include <string>
using namespace std;

class Solution
{
    // Runtime: 3 ms (98.62 %), Memory: 8 MB (95.01 %).
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string rstr;
        int i, j;
        int step = 2 * (numRows - 1), counter = s.length() / step;
        for (i = 0; i < numRows; i++)
        {
            if (i == 0 || i == numRows - 1)
            {
                // zigzag first and last
                for (j = i; j < s.length(); j += step)
                {
                    rstr += s[j];
                }
            }
            else
            {
                // zigzag others
                for (j = 0; j / step <= counter + 1; j += step)
                {
                    if (j - i >= 0 && j - i < s.length())
                    {
                        rstr += s[j - i];
                    }
                    if (j + i < s.length())
                    {
                        rstr += s[j + i];
                    }
                }
            }
        }
        return rstr;
    }
};
