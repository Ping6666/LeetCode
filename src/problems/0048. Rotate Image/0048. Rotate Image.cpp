#include <vector>

using std::vector;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        int tmp = 0;
        int nh = n % 2 == 0 ? n / 2 : n / 2 + 1;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < nh; j++)
            {
                tmp = matrix[i][j];
                // top-left
                matrix[i][j] = matrix[n-j-1][i];
                // bottom-left
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                // bottom-right
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                // top-right
                matrix[j][n-i-1] = tmp;
            }
        }
    }
};
