#include <vector>
#include <unordered_map>
#include <unordered_set>
using std::vector, std::unordered_map, std::unordered_set, std::max;

// Runtime: 160 ms (Beats 95.25 %), Memory: 83.08 MB (Beats 98.02 %).

class Solution
{
private:
    int isLandSum(const int &m, const int &n,
                  vector<vector<int>> &grid, const int &land_id,
                  const int i, const int j)
    {
        if (!isValid(m, n, i, j) || grid[i][j] != 1)
        {
            return 0;
        }

        grid[i][j] = land_id;

        return 1 +
               isLandSum(m, n, grid, land_id, i + 1, j) +
               isLandSum(m, n, grid, land_id, i - 1, j) +
               isLandSum(m, n, grid, land_id, i, j + 1) +
               isLandSum(m, n, grid, land_id, i, j - 1);
    }

    bool isValid(const int &m, const int &n,
                 const int i, const int j)
    {
        return 0 <= i && i < m && 0 <= j && j < n;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int land_id = 2;

        unordered_map<int, int> table;
        bool has_zero = false;

        int ii, jj;
        unordered_set<int> land_ids;

        int max_land = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    has_zero = true;
                    land_ids.clear();

                    ii = i + 1;
                    jj = j;
                    if (isValid(m, n, ii, jj))
                    {
                        if (grid[ii][jj] == 1)
                        {
                            table[land_id] = isLandSum(m, n, grid, land_id, ii, jj);
                            land_id++;
                        }
                        if (grid[ii][jj] != 0)
                        {
                            land_ids.insert(grid[ii][jj]);
                        }
                    }

                    ii = i - 1;
                    jj = j;
                    if (isValid(m, n, ii, jj))
                    {
                        if (grid[ii][jj] == 1)
                        {
                            table[land_id] = isLandSum(m, n, grid, land_id, ii, jj);
                            land_id++;
                        }
                        if (grid[ii][jj] != 0)
                        {
                            land_ids.insert(grid[ii][jj]);
                        }
                    }

                    ii = i;
                    jj = j + 1;
                    if (isValid(m, n, ii, jj))
                    {
                        if (grid[ii][jj] == 1)
                        {
                            table[land_id] = isLandSum(m, n, grid, land_id, ii, jj);
                            land_id++;
                        }
                        if (grid[ii][jj] != 0)
                        {
                            land_ids.insert(grid[ii][jj]);
                        }
                    }

                    ii = i;
                    jj = j - 1;
                    if (isValid(m, n, ii, jj))
                    {
                        if (grid[ii][jj] == 1)
                        {
                            table[land_id] = isLandSum(m, n, grid, land_id, ii, jj);
                            land_id++;
                        }
                        if (grid[ii][jj] != 0)
                        {
                            land_ids.insert(grid[ii][jj]);
                        }
                    }

                    int _land = 1;
                    if (land_ids.size() >= 2)
                    {
                        for (const auto &_id : land_ids)
                        {
                            _land += table[_id];
                        }
                        max_land = max(max_land, _land);
                    }
                }
                else if (grid[i][j] == 1)
                {
                    table[land_id] = isLandSum(m, n, grid, land_id, i, j);
                    land_id++;
                }
            }
        }

        if (max_land != 0)
        {
            return max_land;
        }

        for (const auto &t : table)
        {
            max_land = max(max_land, t.second);
        }
        return has_zero ? max_land + 1 : max_land;
    }
};
