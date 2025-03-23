#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            int _idx = -1;
            for (int j = 0; j < n; j++)
            {
                if (_idx == -1 || matrix[i][_idx] > matrix[i][j])
                {
                    _idx = j;
                }
            }

            for (int j = 0; j < m; j++)
            {
                if (j != i && matrix[i][_idx] < matrix[j][_idx])
                {
                    _idx = -1;
                    break;
                }
            }

            if (_idx != -1)
            {
                ans.push_back(matrix[i][_idx]);
            }
        }

        return ans;
    }
};

/*
class Solution
{
    // Runtime: 10 ms (Beats 93.62 %), Memory: 14.40 MB (Beats 18.75 %).

public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> idx(m, 0);
        for (int i = 0; i < m; i++)
        {
            int min_j = -1;
            for (int j = 0; j < n; j++)
            {
                if (min_j == -1 || matrix[i][min_j] > matrix[i][j])
                {
                    min_j = j;
                }
            }
            idx[i] = min_j;
        }

        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            int max_i = idx[i];
            for (int j = 0; j < m; j++)
            {
                if (j != i && matrix[i][max_i] < matrix[j][max_i])
                {
                    max_i = -1;
                    break;
                }
            }

            if (max_i != -1)
            {
                ans.push_back(matrix[i][max_i]);
            }
        }

        return ans;
    }
};
*/
