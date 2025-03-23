#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 10.39 MB (Beats 82.77 %).

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        if (n < 3 || m < 3)
        {
            return 0;
        }

        int ans = 0;
        bool check;
        int arr[16];

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = 0; j < m - 2; j++)
            {
                // printf("%d %d\n", i, j);

                for (int k = 0; k < 16; k++)
                {
                    arr[k] = 0;
                }

                for (int ii = 0; ii < 3; ii++)
                {
                    for (int jj = 0; jj < 3; jj++)
                    {
                        arr[grid[i + ii][j + jj]]++;
                    }
                }

                check = true;
                for (int k = 1; k < 10 && check; k++)
                {
                    if (arr[k] != 1)
                    {
                        check = false;
                        break;
                    }
                }
                if (!check)
                {
                    continue;
                }

                if (((grid[i][j] + grid[i][j + 1] + grid[i][j + 2] == 15) &&
                     (grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] == 15) &&
                     (grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] == 15)) &&
                    ((grid[i][j] + grid[i + 1][j] + grid[i + 2][j] == 15) &&
                     (grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] == 15) &&
                     (grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] == 15)) &&
                    ((grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == 15) &&
                     (grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] == 15)))
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};
