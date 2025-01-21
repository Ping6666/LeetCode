#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map, std::pair;

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 134.25 MB (Beats 82.01 %).

public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();

        vector<int> row_idx(m * n, -1);
        vector<int> col_idx(m * n, -1);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                row_idx[mat[i][j] - 1] = i;
                col_idx[mat[i][j] - 1] = j;
            }
        }

        vector<int> row(m, n);
        vector<int> col(n, m);

        for (int i = 0; i < arr.size(); i++)
        {
            int r = row_idx[arr[i] - 1];
            int c = col_idx[arr[i] - 1];

            if (--row[r] == 0)
            {
                return i;
            }
            if (--col[c] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};

/*
class Solution
{
    // Runtime: 96 ms (Beats 62.50 %), Memory:170.95 MB (Beats 37.80 %).

public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();

        unordered_map<int, pair<int, int>> _map;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                _map[mat[i][j]] = {i, j};
            }
        }

        vector<int> row(m, n);
        vector<int> col(n, m);

        for (int i = 0; i < arr.size(); i++)
        {
            auto [r, c] = _map[arr[i]];

            if (--row[r] == 0)
            {
                return i;
            }
            if (--col[c] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};
*/
