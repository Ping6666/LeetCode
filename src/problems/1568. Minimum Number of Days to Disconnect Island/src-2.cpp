#include <vector>
using std::vector;

// Runtime: 4 ms (Beats 96.55 %), Memory: 12.40 MB (Beats 93.39 %).
// Tarjan's Algorithm

class Solution
{
private:
    const vector<vector<int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool goodLand(vector<vector<int>> &grid, const int &m, const int &n, int i, int j)
    {
        if (0 <= i && i < m && 0 <= j && j < n)
        {
            if (grid[i][j] == 1)
            {
                return true;
            }
        }
        return false;
    }

    void tarjan(vector<vector<int>> &grid, const int &m, const int &n, vector<vector<int>> &_first, vector<vector<int>> &_low,
                vector<vector<int>> &parent, bool &critical, int &counter, int i, int j)
    {
        _first[i][j] = _low[i][j] = counter++;

        int num_children = 0;

        for (const auto &d : DIRECTIONS)
        {
            int ii = i + d[0];
            int jj = j + d[1];

            if (goodLand(grid, m, n, ii, jj))
            {
                if (_first[ii][jj] == -1)
                {
                    // unchecked
                    num_children++;

                    parent[ii][jj] = i * n + j;

                    tarjan(grid, m, n, _first, _low, parent, critical, counter, ii, jj);

                    _low[i][j] = std::min(_low[i][j], _low[ii][jj]);

                    if (_low[ii][jj] >= _first[i][j] && parent[i][j] != -1)
                    {
                        // magic
                        critical = true;
                    }
                }
                else if (ii * n + jj != parent[i][j])
                {
                    // got different path
                    _low[i][j] = std::min(_low[i][j], _first[ii][jj]);
                }
            }
        }

        if (parent[i][j] == -1 && num_children > 1)
        {
            // magic
            critical = true;
        }
    }

public:
    int minDays(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> _first(m, vector<int>(n, -1));
        vector<vector<int>> _low(m, vector<int>(n, -1));
        vector<vector<int>> parent(m, vector<int>(n, -1));

        bool critical = false;
        int counter = 0;

        int cell_counter = 0, land_counter = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    cell_counter++;
                    if (_first[i][j] == -1)
                    {
                        tarjan(grid, m, n, _first, _low, parent, critical, counter, i, j);
                        land_counter++;
                    }
                }
            }
        }

        if (land_counter != 1)
        {
            return 0;
        }

        if (cell_counter == 1)
        {
            return 1;
        }

        if (critical)
        {
            return 1;
        }

        return 2;
    }
};
