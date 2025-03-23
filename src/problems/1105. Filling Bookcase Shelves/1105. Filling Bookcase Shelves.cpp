#include <vector>
using std::vector, std::max, std::min;

// Runtime: 0 ms (Beats 100.00 %), Memory: 11.06 MB (Beats 58.66 %).

class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();

        // store the height
        // 0 -> put none of the books
        // 1 -> had put first book
        // 2 -> had put first and second book
        vector<int> dp(n + 1, 0);

        dp[0] = 0;

        int remainingWidth, maxHeight;
        int j;

        for (int i = 0; i < n; i++)
        {
            remainingWidth = shelfWidth - books[i][0];
            maxHeight = books[i][1];
            dp[i + 1] = dp[i] + maxHeight;

            j = i - 1;
            while (j >= 0)
            {
                remainingWidth -= books[j][0];

                // if there still got room
                if (remainingWidth < 0)
                {
                    break;
                }

                maxHeight = max(books[j][1], maxHeight);
                dp[i + 1] = min(dp[i + 1], dp[j] + maxHeight);

                j--;
            }
        }

        return dp[n];
    }
};
