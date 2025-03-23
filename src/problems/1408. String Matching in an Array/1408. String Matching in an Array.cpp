#include <vector>
#include <string>
#include <unordered_set>
using std::vector, std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 11.23 MB (Beats 69.19 %).

class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        int n = words.size();
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }

                if (words[j].find(words[i]) != -1)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
