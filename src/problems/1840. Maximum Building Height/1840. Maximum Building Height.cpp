#include <vector>
#include <algorithm>

using std::vector, std::sort;

class Solution
{
public:
    int maxBuilding(int n, vector<vector<int>> &restrictions)
    {
        sort(restrictions.begin(), restrictions.end());

        for (int i = restrictions.size() - 1; i > 0; i--)
        {
            if ((restrictions[i][1] < restrictions[i - 1][1]) &&
                (restrictions[i - 1][1] - restrictions[i][1] > restrictions[i][0] - restrictions[i - 1][0]))
            {
                restrictions[i - 1][1] = restrictions[i][0] - restrictions[i - 1][0] + restrictions[i][1];
            }
        }

        int p_idx = 1, p = 0, m = 0;
        for (int i = 0, c_idx, c; i < restrictions.size(); i++)
        {
            c_idx = restrictions[i][0];
            c = restrictions[i][1];

            // printf("%d %d\n", c_idx, c);

            if (c > p)
            {
                if (c - p > c_idx - p_idx)
                {
                    m = max(m, p + c_idx - p_idx);
                }
                else
                {
                    int d = (c_idx - p_idx) - (p - c);
                    int d2 = d / 2;
                    m = max(m, p + d2);
                }
            }
            else if (p - c < c_idx - p_idx)
            {
                int d = (c_idx - p_idx) - (p - c);
                int d2 = d / 2;
                m = max(m, p + d2);
            }
            p = min(c, p + c_idx - p_idx);
            p_idx = c_idx;
        }
        if (p_idx != n)
        {
            m = max(m, p + n - p_idx);
        }
        return m;
    }
};
