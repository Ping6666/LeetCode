#include <vector>
using std::vector;

// Runtime: 7 ms (Beats 86.90 %), Memory: 13.65 MB (Beats 48.36 %).

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        int face = 0;
        // 0 right, 1 down, 2 left, 3 up
        int step = 1;

        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});

        while (ans.size() < rows * cols)
        {
            for (int i = 0; i < step; i++)
            {
                if (face == 0)
                {
                    cStart++;
                }
                else if (face == 1)
                {
                    rStart++;
                }
                else if (face == 2)
                {
                    cStart--;
                }
                else
                {
                    rStart--;
                };

                if ((rStart >= 0 && rStart < rows) && (cStart >= 0 && cStart < cols))
                {
                    ans.push_back({rStart, cStart});
                }
            }

            face = (face + 1) % 4;
            if (face % 2 == 0)
            {
                step++;
            }
        }

        return ans;
    }
};
