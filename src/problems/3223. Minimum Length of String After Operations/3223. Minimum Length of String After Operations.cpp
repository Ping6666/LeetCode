#include <string>
using std::string;

// Runtime: 3 ms (Beats 98.79 %), Memory: 32.05 MB (Beats 74.19 %).

class Solution
{
public:
    int minimumLength(string s)
    {
        int arr[26] = {0};
        for (const auto &c : s)
        {
            arr[c - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] == 0)
            {
                continue;
            }

            if (arr[i] % 2 == 0)
            {
                ans += 2;
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};
