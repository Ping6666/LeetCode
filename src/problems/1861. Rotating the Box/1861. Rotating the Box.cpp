#include <vector>
using std::vector;

// Runtime: 185 ms (Beats 80.83 %), Memory: 56.16 MB (Beats 96.34 %).

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for (int i = 0; i < m; i++)
        {
            int r = n, c = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if (box[i][j] == '.')
                {
                    // do nothing
                }
                else if (box[i][j] == '#')
                {
                    c++;
                }
                else
                {
                    // '*' case
                    for (int k = r - 1; k > j; k--)
                    {
                        if (c > 0)
                        {
                            box[i][k] = '#';
                            c--;
                        }
                        else
                        {
                            box[i][k] = '.';
                        }
                    }

                    r = j;
                    c = 0;
                }
            }

            if (c > 0)
            {
                for (int k = r - 1; k >= 0; k--)
                {
                    if (c > 0)
                    {
                        box[i][k] = '#';
                        c--;
                    }
                    else
                    {
                        box[i][k] = '.';
                    }
                }
            }

            for (int j = 0; j < n; j++)
            {
                ans[j][m - i - 1] = box[i][j];
            }
        }

        return ans;
    }
};
