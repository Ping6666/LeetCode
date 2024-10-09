#include <vector>
#include <queue>
using std::vector, std::queue, std::pair;

// Runtime: 195 ms (Beats 92.85 %), Memory: 94.74 MB (Beats 73.27 %).

class Solution
{
private:
    bool isIsland(int i, int j, const int &num_rows, const int &num_cols, vector<vector<int>> &grid)
    {
        return grid[i][j] == 1;
    }

    bool bfs(int i, int j, const int &num_rows, const int &num_cols,
             vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {

        if (i < 0 || i >= num_rows || j < 0 || j >= num_cols || !isIsland(i, j, num_rows, num_cols, grid2))
        {
            return true;
        }

        grid2[i][j] = 0;
        return isIsland(i, j, num_rows, num_cols, grid1) &
               bfs(i, j + 1, num_rows, num_cols, grid1, grid2) &
               bfs(i, j - 1, num_rows, num_cols, grid1, grid2) &
               bfs(i + 1, j, num_rows, num_cols, grid1, grid2) &
               bfs(i - 1, j, num_rows, num_cols, grid1, grid2);
    }

public:
    int
    countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int num_rows = grid2.size();
        int num_cols = grid2[0].size();

        int counter = 0;

        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                if (isIsland(i, j, num_rows, num_cols, grid2) &&
                    bfs(i, j, num_rows, num_cols, grid1, grid2))
                {
                    counter++;
                }
            }
        }

        return counter;
    }
};
