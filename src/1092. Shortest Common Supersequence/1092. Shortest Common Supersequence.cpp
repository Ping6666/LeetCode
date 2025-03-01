#include <string>
#include <vector>
#include <algorithm>
using std::string, std::vector, std::min, std::reverse;

// Runtime: 22 ms (Beats 91.23 %), Memory: 26.76 MB (Beats 70.92 %).
// LeetCode Editorial - Approach 4: Most Optimal - Space Optimized Dynamic Programming

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int str1_len = str1.size(), str2_len = str2.size();

        vector<vector<int>> dp(str1_len + 1, vector<int>(str2_len + 1, 0));
        for (int i = 0; i <= str1_len; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= str2_len; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= str1_len; i++)
        {
            for (int j = 1; j <= str2_len; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    // same
                    // use up-left
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    // diff
                    // use min(up, left)
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        // for (int i = 0; i <= str1_len; i++)
        // {
        //     for (int j = 0; j <= str2_len; j++)
        //     {
        //         printf("%d ", dp[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");

        string ans = "";

        int str1_idx = str1_len - 1, str2_idx = str2_len - 1;
        for (int i = 0; i < dp[str1_len][str2_len]; i++)
        {
            if (str1_idx >= 0 && str2_idx >= 0)
            {
                if (str1[str1_idx] == str2[str2_idx])
                {
                    ans += str1[str1_idx];
                    str1_idx--;
                    str2_idx--;
                }
                else if (dp[str1_idx + 1][str2_idx] > dp[str1_idx][str2_idx + 1])
                {
                    // pick str1
                    ans += str1[str1_idx];
                    str1_idx--;
                }
                else
                {
                    // pick str2
                    ans += str2[str2_idx];
                    str2_idx--;
                }
            }
            else
            {
                break;
            }
        }

        while (str1_idx >= 0)
        {
            ans += str1[str1_idx];
            str1_idx--;
        }
        while (str2_idx >= 0)
        {
            ans += str2[str2_idx];
            str2_idx--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
