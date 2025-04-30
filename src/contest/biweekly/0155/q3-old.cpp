#include <string>
#include <vector>
using std::string, std::vector;

// TLE

class Solution
{
private:
    bool h_check(const vector<vector<char>> &grid, const string &pattern,
                 const int i, const int j,
                 vector<vector<bool>> &mask)
    {
        const int m = grid.size(), n = grid[0].size();
        const int l = pattern.size();

        // check

        bool check = true;
        int ii = i, jj = j;
        for (int ll = 0; ll < l && check; ll++)
        {
            if (ii == m)
            {
                check = false;
                break;
            }

            if (jj == n)
            {
                ll--;

                // wrap
                jj = 0;
                ii++;
            }
            else
            {
                if (grid[ii][jj] != pattern[ll])
                {
                    check = false;
                    break;
                }

                jj++;
            }
        }

        if (!check)
        {
            return false;
        }

        // set

        ii = i, jj = j;
        for (int ll = 0; ll < l; ll++)
        {
            if (jj == n)
            {
                ll--;

                // wrap
                jj = 0;
                ii++;
            }
            else
            {
                mask[ii][jj] = true;
                jj++;
            }
        }
        return true;
    }

    bool v_check(const vector<vector<char>> &grid, const string &pattern,
                 const int i, const int j,
                 vector<vector<bool>> &mask)
    {
        const int m = grid.size(), n = grid[0].size();
        const int l = pattern.size();

        // check

        bool check = true;
        int ii = i, jj = j;
        for (int ll = 0; ll < l && check; ll++)
        {
            if (jj == n)
            {
                check = false;
                break;
            }

            if (ii == m)
            {
                ll--;

                // wrap
                ii = 0;
                jj++;
            }
            else
            {
                if (grid[ii][jj] != pattern[ll])
                {
                    check = false;
                    break;
                }

                ii++;
            }
        }

        if (!check)
        {
            return false;
        }

        // set

        ii = i, jj = j;
        for (int ll = 0; ll < l; ll++)
        {
            if (ii == m)
            {
                ll--;

                // wrap
                ii = 0;
                jj++;
            }
            else
            {
                mask[ii][jj] = true;
                ii++;
            }
        }
        return true;
    }

public:
    int countCells(vector<vector<char>> &grid, string pattern)
    {
        const int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> horizontal(m, vector<bool>(n, false));
        vector<vector<bool>> vertical(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                h_check(grid, pattern, i, j, horizontal);
                v_check(grid, pattern, i, j, vertical);
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (horizontal[i][j] && vertical[i][j])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
