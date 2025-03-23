#include <string>
#include <vector>
using namespace std;

class Solution
{
    // Runtime: 0 ms (100.00 %), Memory: 9.2 MB (77.84 %).
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        char tmp;
        int counter = 0;
        if (strs.size() == 1)
            return strs[0];
        for (int i = 0; i < strs.size(); i++)
        {
            if (strs[i].length() <= counter)
                break;
            if (i == 0)
            {
                tmp = strs[i][counter];
            }
            else if (tmp != strs[i][counter])
                break;
            if (i == strs.size() - 1)
            {
                counter++;
                i = -1;
            }
        }
        return strs[0].substr(0, counter);
    }
};
