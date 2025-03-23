#include <vector>
#include <unordered_set>
using std::vector, std::unordered_set;

// Runtime: 237 ms (Beats 11.34 %), Memory: 204.11 MB (Beats 31.37 %).

// using magic can lower the runtime, just use another matrix to store the guard & wall

class Solution
{
private:
    int magic(const int &n, int i, int j)
    {
        return n * i + j;
    }

    void dfs(const int &m, const int &n,
             const int dy, const int dx,
             int i, int j,
             unordered_set<int> &obs,
             vector<vector<bool>> &table)
    {
        i += dy;
        j += dx;

        while (0 <= i && i < m && 0 <= j && j < n)
        {
            if (obs.find(magic(n, i, j)) != obs.end())
            {
                // got wall or guard
                return;
            }

            table[i][j] = false;

            i += dy;
            j += dx;
        }
    }

public:
    int countUnguarded(int m, int n,
                       vector<vector<int>> &guards,
                       vector<vector<int>> &walls)
    {
        vector<vector<bool>> table(m, vector<bool>(n, true));

        unordered_set<int> obs;
        for (const auto &g : guards)
        {
            obs.insert(magic(n, g[0], g[1]));
            table[g[0]][g[1]] = false;
        }
        for (const auto &w : walls)
        {
            obs.insert(magic(n, w[0], w[1]));
            table[w[0]][w[1]] = false;
        }

        for (const auto &g : guards)
        {
            dfs(m, n, 0, 1, g[0], g[1], obs, table);
            dfs(m, n, 1, 0, g[0], g[1], obs, table);
            dfs(m, n, 0, -1, g[0], g[1], obs, table);
            dfs(m, n, -1, 0, g[0], g[1], obs, table);
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (table[i][j])
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};
