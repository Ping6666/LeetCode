#include <vector>
#include <unordered_set>
using std::vector, std::unordered_set;

// Runtime: 0 ms (Beats 100.00 %), Memory: 27.45 MB (Beats 21.52 %).

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        int _len;
        vector<int> idx;

        unordered_set<int> servers;

        for (int i = 0; i < m; i++)
        {
            idx.clear();
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    idx.push_back(j);
                }
            }

            _len = idx.size();
            if (_len > 1)
            {
                for (int j = 0; j < _len; j++)
                {
                    servers.insert(i * n + idx[j]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            idx.clear();
            for (int j = 0; j < m; j++)
            {
                if (grid[j][i] == 1)
                {
                    idx.push_back(j);
                }
            }

            _len = idx.size();
            if (_len > 1)
            {
                for (int j = 0; j < _len; j++)
                {
                    servers.insert(i + idx[j] * n);
                }
            }
        }

        return servers.size();
    }
};
