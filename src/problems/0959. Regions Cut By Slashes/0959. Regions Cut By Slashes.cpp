#include <vector>
#include <string>
using std::vector, std::string;

// Runtime: 23 ms (Beats 14.91 %), Memory: 13.31 MB (Beats 34.69 %).

// NOTE magic number must be 3!

class Solution
{
private:
    void flood(vector<vector<bool>> &table, int row, int col)
    {
        int n = table.size();
        if (row < 0 || row >= n)
        {
            return;
        }
        if (col < 0 || col >= n)
        {
            return;
        }
        if (table[row][col])
        {
            return;
        }

        table[row][col] = true;
        flood(table, row + 1, col);
        flood(table, row - 1, col);
        flood(table, row, col + 1);
        flood(table, row, col - 1);
    }

public:
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        int magic = 3;
        vector<vector<bool>> table(n * magic, vector<bool>(n * magic, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '/')
                {
                    for (int k = 0; k < magic; k++)
                    {
                        table[i * magic + k][j * magic + (magic - k - 1)] = true;
                    }
                }
                else if (grid[i][j] == '\\')
                {
                    for (int k = 0; k < magic; k++)
                    {
                        table[i * magic + k][j * magic + k] = true;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n * magic; i++)
        {
            for (int j = 0; j < n * magic; j++)
            {
                if (!table[i][j])
                {
                    flood(table, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};
