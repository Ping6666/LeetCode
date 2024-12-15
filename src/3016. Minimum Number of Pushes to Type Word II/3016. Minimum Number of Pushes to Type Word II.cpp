#include <string>
#include <algorithm>
using std::string, std::sort;

// Runtime: 62 ms (Beats 94.45 %), Memory: 25.75 MB (Beats 51.72 %).

class Solution
{
public:
    int minimumPushes(string word)
    {
        int arr[26] = {};
        for (auto &c : word)
        {
            arr[c - 'a']++;
        }

        int indices[26] = {};
        for (int i = 0; i < 26; i++)
        {
            indices[i] = i;
        }

        sort(&indices[0], &indices[26], [&](int lhs, int rhs)
             { return arr[lhs] > arr[rhs]; });

        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            // printf("%c %d %d\n", indices[i] + 'a', arr[indices[i]], ((i / 8) + 1));
            ans += arr[indices[i]] * ((i / 8) + 1);
        }

        return ans;
    }
};
