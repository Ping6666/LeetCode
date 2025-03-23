#include <string>
#include <vector>
using std::string, std::vector, std::max;

// Runtime: 51 ms (Beats 64.84 %), Memory: 106.70 MB (Beats 56.16 %).

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<int> g_arr(26, 0);
        for (const auto &w : words2)
        {
            vector<int> arr(26, 0);
            for (const auto &c : w)
            {
                arr[c - 'a']++;
            }

            for (int i = 0; i < 26; i++)
            {
                g_arr[i] = max(g_arr[i], arr[i]);
            }
        }

        vector<string> ans;
        for (const auto &w : words1)
        {
            vector<int> arr(26, 0);
            for (const auto &c : w)
            {
                arr[c - 'a']++;
            }

            bool check = true;
            for (int i = 0; i < 26; i++)
            {
                if (g_arr[i] > arr[i])
                {
                    check = false;
                    break;
                }
            }

            if (check)
            {
                ans.push_back(w);
            }
        }
        return ans;
    }
};
