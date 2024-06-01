#include <stdio.h>

#include <vector>

using namespace std;

class Solution
{
    // Runtime: 28 ms (Beats 38.98 %), Memory: 6.5 MB (Beats 96.52 %).

public:
    double knightProbability(int n, int k, int row, int column)
    {
        vector<pair<int, int>> next = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

        vector prev_dp(n, vector<double>(n, 0));
        vector curr_dp(n, vector<double>(n, 0));

        prev_dp[row][column] = 1;

        for (int _k = 0; _k < k; _k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    curr_dp[i][j] = 0;

                    for (int idx = 0; idx < 8; idx++)
                    {
                        // next.size() is 8

                        int _i = i - next[idx].first;
                        int _j = j - next[idx].second;

                        if ((_i >= 0 && _i < n) && (_j >= 0 && _j < n))
                        {
                            // on the chessboard

                            curr_dp[i][j] += prev_dp[_i][_j] / 8;
                        }
                    }
                }
            }

            prev_dp.swap(curr_dp);
        }

        double probability = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                probability += prev_dp[i][j];
            }
        }

        return probability;
    }
};

int main()
{
    Solution s;

    s = Solution();
    printf("%f\n", s.knightProbability(3, 2, 0, 0));

    s = Solution();
    printf("%f\n", s.knightProbability(1, 0, 0, 0));

    s = Solution();
    printf("%f\n", s.knightProbability(3, 3, 0, 0));

    s = Solution();
    printf("%f\n", s.knightProbability(8, 30, 6, 4));

    return 0;
}
