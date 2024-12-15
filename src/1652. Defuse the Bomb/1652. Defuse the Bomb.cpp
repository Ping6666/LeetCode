#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 10.24 MB (Beats 84.00 %).

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0)
        {
            return ans;
        }

        bool neg = k < 0;

        int ii;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= abs(k); j++)
            {
                if (!neg)
                {
                    ii = i + j;
                }
                else
                {
                    ii = i - j;
                }

                if (ii < 0)
                {
                    ii += n;
                }
                else if (ii >= n)
                {
                    ii -= n;
                }

                ans[i] += code[ii];
            }
        }

        return ans;
    }
};
