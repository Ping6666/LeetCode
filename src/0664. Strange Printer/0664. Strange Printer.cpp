#include <stdio.h>

#include <string>  // string
#include <cstring> // memset

using namespace std;

class Solution
{
    // Runtime: 34 ms (Beats 79.35 %), Memory: 6 MB (Beats 98.09 %).

public:
    int strangePrinter(string s)
    {
        int n = s.length();

        int dp[n][n];
        memset(dp, n, n * n * sizeof(int));

        for (int length = 1; length <= n; length++)
        {
            for (int left = 0; left <= n - length; left++)
            {
                int right = left + length - 1;

                int j = -1;
                for (int i = left; i < right; i++)
                {
                    if (s[i] != s[right])
                    {
                        // find first diff. char
                        j = i;
                        break;
                    }
                }

                if (j != -1)
                {
                    for (int i = j; i < right; i++)
                    {
                        // from the diff. char to the end of curr. range [left, right]
                        dp[left][right] = min(dp[left][right], 1 + dp[j][i] + dp[i + 1][right]);

                        // 1 + dp[j][i] + dp[i + 1][right]
                        //   1                : the same char front
                        //   dp[j][i]         : the first diff. char to curr. i
                        //   dp[i + 1][right] : curr. i to the end (exclude back)
                    }
                }
                else
                {
                    // if found no diff. char
                    //   1. left == right
                    //   2. all char are the same
                    dp[left][right] = 0;
                }
            }
        }

        return dp[0][n - 1] + 1;
    }
};

int main()
{
    string str;

    Solution s;
    int ans;

    str = "aaabbb";
    s = Solution();
    ans = s.strangePrinter(str);
    printf("%d\n", ans);

    str = "aaaaaaaabbbbbbbb";
    s = Solution();
    ans = s.strangePrinter(str);
    printf("%d\n", ans);

    str = "aba";
    s = Solution();
    ans = s.strangePrinter(str);
    printf("%d\n", ans);

    str = "abab";
    s = Solution();
    ans = s.strangePrinter(str);
    printf("%d\n", ans);

    return 0;
}
