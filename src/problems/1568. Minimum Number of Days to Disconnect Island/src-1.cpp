#include <vector>
using std::vector;

// NOTE fail to find critical point

class Solution
{
private:
    void flood(vector<vector<int>> &grid, const int &m, const int &n, int i, int j)
    {
        if (i < 0 || i >= m)
        {
            return;
        }
        if (j < 0 || j >= n)
        {
            return;
        }
        if (grid[i][j] == 0)
        {
            return;
        }

        grid[i][j] = 0;
        flood(grid, m, n, i + 1, j);
        flood(grid, m, n, i - 1, j);
        flood(grid, m, n, i, j + 1);
        flood(grid, m, n, i, j - 1);
    }

    int waterCount(vector<vector<int>> &grid, const int &i, const int &j, const int &m, const int &n)
    {
        return (i - 1 < 0 || grid[i - 1][j] == 0) +
               (j - 1 < 0 || grid[i][j - 1] == 0) +
               (i + 1 >= m || grid[i + 1][j] == 0) +
               (j + 1 >= n || grid[i][j + 1] == 0);
    }

    void checker(vector<vector<int>> &grid, const int &m, const int &n, int *least_edge_info)
    {
        // least_edge_info: the info of (i, j)
        //   which is {edge count, island size}
        //     and the island size is including (i, j), count up to 3 (is short will return 2 or 3)

        int critical_count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int water_count = waterCount(grid, i, j, m, n);
                    if (water_count >= 2)
                    {
                        if ((4 - water_count) <= least_edge_info[0])
                        {
                            least_edge_info[0] = (4 - water_count);

                            if (water_count == 2)
                            {
                                // may got critical point
                                if (((i - 1 < 0 || grid[i - 1][j] == 0) && (i + 1 >= m || grid[i + 1][j] == 0)) ||
                                    ((j - 1 < 0 || grid[i][j - 1] == 0) && (j + 1 >= n || grid[i][j + 1] == 0)))
                                {
                                    critical_count++;
                                }

                                least_edge_info[1] = 3;
                            }
                            else if (water_count == 3)
                            {
                                int island_size = 1;
                                if (i - 1 >= 0 && grid[i - 1][j] == 1)
                                {
                                    island_size += 4 - waterCount(grid, i - 1, j, m, n);
                                }
                                else if (j - 1 >= 0 && grid[i][j - 1] == 1)
                                {
                                    island_size += 4 - waterCount(grid, i, j - 1, m, n);
                                }
                                else if (i + 1 < m && grid[i + 1][j] == 1)
                                {
                                    island_size += 4 - waterCount(grid, i + 1, j, m, n);
                                }
                                else if (j + 1 < n && grid[i][j + 1] == 1)
                                {
                                    island_size += 4 - waterCount(grid, i, j + 1, m, n);
                                }

                                least_edge_info[1] = std::min(island_size, 3);
                            }
                            else if (water_count == 4)
                            {
                                least_edge_info[1] = 1;
                            }
                        }
                    }
                }
            }
        }

        // printf("%d\n", critical_count);

        if (critical_count == 1 && least_edge_info[0] == 2)
        { // got only one critical point
            least_edge_info[0] = 1;
        }
    }

public:
    int minDays(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        int island_count = 0;
        int least_edge_info[2] = {4, -1};
        checker(grid, m, n, least_edge_info);

        // printf("%d %d\n", least_edge_info[0], least_edge_info[1]);

        for (int i = 0; i < m && island_count <= 1; i++)
        {
            for (int j = 0; j < n && island_count <= 1; j++)
            {
                if (grid[i][j] == 1)
                {
                    flood(grid, m, n, i, j);
                    island_count++;

                    if (island_count > 1)
                    {
                        break;
                    }
                }
            }
        }
        // printf("%d\n", island_count);

        if (island_count != 1)
        {
            return 0;
        }

        if (least_edge_info[0] == 0)
        {
            return 1;
        }
        else if (least_edge_info[0] == 1)
        {
            if (least_edge_info[1] == 2)
            {
                return 2;
            }
            else if (least_edge_info[1] == 3)
            {
                return 1;
            }
            else
            {
                // should not walk here
                return -1;
            }
        }
        else if (least_edge_info[0] == 2)
        {
            return 2;
        }
        else
        {
            // should not walk here
            return -1;
        }
    }
};

// 1,1,1,1,0,1,1,1,1
// 1,1,1,1,0,1,1,1,1
// 0,0,0,1,0,1,0,0,0
// 1,1,1,1,1,1,1,1,1
// 1,1,1,1,1,1,1,1,1
// 1,1,1,1,1,1,1,1,1
