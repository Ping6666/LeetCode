#include <vector>
using std::vector, std::min;

// Runtime: 32 ms (Beats 85.33 %), Memory: 35.92 MB (Beats 27.54 %).

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int n = rowSum.size(), m = colSum.size();

        vector<vector<int>> table(n, vector<int>(m, 0));
        int c;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                c = min(rowSum[i], colSum[j]);

                table[i][j] = c;
                rowSum[i] -= c;
                colSum[j] -= c;
            }
        }

        return table;
    }
};
