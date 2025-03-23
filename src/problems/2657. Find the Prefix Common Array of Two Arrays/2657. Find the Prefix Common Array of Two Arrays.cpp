#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 85.70 MB (Beats 92.22 %).

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();

        unsigned long long mask_A = 0, mask_B = 0;
        unsigned long long t;

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            mask_A |= (unsigned long long)1 << A[i];
            mask_B |= (unsigned long long)1 << B[i];

            ans.push_back(0);
            t = mask_A & mask_B;
            for (int j = 1; j <= n; j++)
            {
                if ((t >> j) & 1 == 1)
                {
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};
