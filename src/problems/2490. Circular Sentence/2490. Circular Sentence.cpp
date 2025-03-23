#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 8.00 MB (Beats 96.30 %).

class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        int n = sentence.size();

        if (sentence[0] != sentence[n - 1])
        {
            return false;
        }

        for (int i = 0; i < n; i++)
        {
            if (sentence[i] == ' ')
            {
                if (sentence[i - 1] != sentence[i + 1])
                {
                    return false;
                }
            }
        }

        return true;
    }
};
