#include <string>
#include <vector>
#include <unordered_map>
using std::string, std::vector, std::unordered_map;

// Runtime: 0 ms (Beats 100.00 %), Memory: 8.69 MB (Beats 97.06 %).

class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> str_map;

        int n;

        n = s1.size();
        for (int i = 0, j = 0; i < n; i++)
        {
            if (s1[i] == ' ')
            {
                str_map[s1.substr(i - j, j)]++;
                j = 0;
            }
            else if (i == n - 1)
            {
                j++;

                str_map[s1.substr(i - j + 1, j)]++;
                j = 0;
            }
            else
            {
                j++;
            }
        }

        n = s2.size();
        for (int i = 0, j = 0; i < n; i++)
        {
            if (s2[i] == ' ')
            {
                str_map[s2.substr(i - j, j)]++;
                j = 0;
            }
            else if (i == n - 1)
            {
                j++;

                str_map[s2.substr(i - j + 1, j)]++;
                j = 0;
            }
            else
            {
                j++;
            }
        }

        vector<string> ans;
        for (const auto &s : str_map)
        {
            if (s.second == 1)
            {
                ans.push_back(s.first);
            }
        }

        return ans;
    }
};
