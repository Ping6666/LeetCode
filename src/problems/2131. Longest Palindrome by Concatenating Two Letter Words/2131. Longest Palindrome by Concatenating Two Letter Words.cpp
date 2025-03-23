#include <vector>
#include <string>
#include <iostream>
using std::vector, std::string, std::min;

class Solution
{
    // Runtime: 139 ms (Beats 99.04 %), Memory: 171.30 MB (Beats 97.12 %).

public:
    int longestPalindrome(vector<string> &words)
    {
        // magic
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);

        int l = 26;
        vector<vector<int>> table(l, vector<int>(l, 0));

        for (auto w : words)
        {
            table[(w[0] - 'a')][(w[1] - 'a')]++;
        }

        int ans = 0;
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < i; j++)
            {
                ans += min(table[i][j], table[j][i]);
            }
        }

        bool odd = false;
        for (int i = 0; i < l; i++)
        {
            ans += table[i][i] / 2;

            if (!odd && table[i][i] % 2 == 1)
            {
                odd = true;
            }
        }
        ans *= 2;

        if (odd)
        {
            ans++;
        }

        return ans * 2;
    }
};
