#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 8.23 MB (Beats 85.97 %).

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int freq1[26] = {0};
        int freq2[26] = {0};
        int n = s1.size();

        int diff = 0;

        for (int i = 0; i < n; i++)
        {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;

            if (s1[i] != s2[i])
            {
                diff++;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] != freq2[i])
            {
                return false;
            }
        }

        if (diff > 2)
        {
            return false;
        }
        return true;
    }
};
