#include <set>
#include <string>
using namespace std;

class Solution
{
    // Runtime: 40 ms (26.07 %), Memory: 13.5 MB (12.69 %).
    /*
    other solutions
    1. use vector store last index
    2. use vector to store char's counter
    */
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> subcharset;
        int slen = s.length();
        int prevleft = 0, counter = 0;
        for (int i = 0; i < slen; i++)
        {
            if (subcharset.count(s[i]))
            {
                int tmpi = i - 1, currleft = i;
                // currleft stores the first found (should be only found) between prevleft and i - 1
                while (tmpi >= prevleft)
                {
                    // if found s[i] which means meeting current left boundary
                    if (s[i] == s[tmpi])
                    {
                        currleft = tmpi;
                        break;
                    }
                    tmpi--;
                }
                // erase all char inside the window (between prevleft and currleft)
                for (int j = prevleft; j <= currleft; j++)
                    subcharset.erase(s[j]);
                prevleft = currleft + 1;
            }
            subcharset.insert(s[i]);
            if (counter < subcharset.size())
                counter = subcharset.size();
        }
        return counter;
    }
};
