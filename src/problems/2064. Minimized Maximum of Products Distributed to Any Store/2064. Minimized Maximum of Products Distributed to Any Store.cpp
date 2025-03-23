#include <vector>
using std::vector;

// Runtime: 131 ms (Beats 21.35 %), Memory: 87.12 MB (Beats 89.12 %).

class Solution
{
private:
    bool canFit(int n, vector<int> &quantities, int num)
    {
        int j = 0;
        int r = quantities[j];

        for (int i = 0; i < n; i++)
        {
            if (r <= num)
            {
                j++;

                if (j == quantities.size())
                {
                    return true;
                }
                else
                {
                    r = quantities[j];
                }
            }
            else
            {
                r -= num;
            }
        }

        return false;
    }

public:
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int l = 0, r = *max_element(quantities.begin(), quantities.end());

        int m, ans = -1;
        while (l <= r)
        {
            m = l + (r - l) / 2;
            if (canFit(n, quantities, m))
            {
                r = m - 1;
                ans = m;
            }
            else
            {
                l = m + 1;
            }
        }

        return ans;
    }
};
