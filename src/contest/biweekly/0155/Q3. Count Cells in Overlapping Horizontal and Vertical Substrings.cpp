#include <string>
#include <vector>
using std::string, std::vector;

// Runtime: 20 ms (Beats 99.18 %), Memory: 58.45 MB (Beats 98.90 %).

class Solution
{
private:
    vector<int> computeLongestPrefixSuffix(const string &pattern)
    {
        int n = pattern.size();
        vector<int> lps(n, 0);

        for (int i = 1, l = 0; i < n;)
        {
            if (pattern[i] == pattern[l])
            {
                // match then inc. the len.
                l++;
                lps[i] = l;
                i++;
            }
            else if (l != 0)
            {
                // try to check prev. longest prefix-suffix
                l = lps[l - 1];
            }
            else
            {
                // not found, reset
                lps[i] = 0;
                i++;
            }
        }
        return lps;
    }

public:
    int countCells(vector<vector<char>> &grid, string pattern)
    {
        // ref. KMP 1910
        vector<int> kmp_lps = computeLongestPrefixSuffix(pattern);

        const int m = grid.size(), n = grid[0].size(), l = pattern.size();
        const int mn = m * n;

        vector<vector<bool>> horizontal(m, vector<bool>(n, false));
        vector<vector<bool>> vertical(m, vector<bool>(n, false));

        // horizontal
        for (int k = 0, idx = 0; k < mn; k++)
        {
            int i = k / n, j = k % n;

            if ((mn - k) < (l - idx))
            {
                break;
            }

            while (idx > 0 && grid[i][j] != pattern[idx])
            {
                // rollback
                idx = kmp_lps[idx - 1];
            }

            if (grid[i][j] == pattern[idx])
            {
                // hit
                idx++;
            }

            if (idx == l)
            {
                for (int kk = 0; kk < l; kk++)
                {
                    int ii = (k - kk) / n, jj = (k - kk) % n;

                    // very important
                    if (horizontal[ii][jj])
                    {
                        break;
                    }
                    horizontal[ii][jj] = true;
                }

                // idx = 0;
                idx = kmp_lps[idx - 1];
            }
        }

        // vertical
        for (int k = 0, idx = 0; k < mn; k++)
        {
            int i = k % m, j = k / m;

            if ((mn - k) < (l - idx))
            {
                break;
            }

            while (idx > 0 && grid[i][j] != pattern[idx])
            {
                // rollback
                idx = kmp_lps[idx - 1];
            }

            if (grid[i][j] == pattern[idx])
            {
                // hit
                idx++;
            }

            if (idx == l)
            {
                for (int kk = 0; kk < l; kk++)
                {
                    int ii = (k - kk) % m, jj = (k - kk) / m;

                    // very important
                    if (vertical[ii][jj])
                    {
                        break;
                    }
                    vertical[ii][jj] = true;
                }

                // idx = 0;
                idx = kmp_lps[idx - 1];
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
