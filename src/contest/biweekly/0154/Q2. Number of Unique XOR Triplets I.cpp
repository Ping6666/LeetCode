#include <vector>
#include <unordered_set>
#include <cmath>
using std::vector, std::unordered_set, std::pow;

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        /*
        const int n = nums.size();
        vector<vector<int>> table(n, vector<int>(n, -1));

        unordered_set<int> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (table[i][j] == -1)
                {
                    table[i][j] = nums[i] ^ nums[j];
                }

                for (int k = j; k < n; k++)
                {
                    ans.insert(table[i][j] ^ nums[k]);
                }
            }
        }
        return ans.size();
        */

        // return n next pow of 2
        // for (int i = 3; i <= 32; i++)
        // {
        //     int p = 0;
        //     int ii = i;
        //     while (ii > 0)
        //     {
        //         ii >>= 1;
        //         p++;
        //     }
        //     printf("%d %d %d\n", i, p, int(pow(2, p)));
        // }

        const int n = nums.size();
        // just found some rules
        if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }

        int p = 0;
        int _n = n;
        while (_n > 0)
        {
            _n >>= 1;
            p++;
        }
        return int(pow(2, p));
    }
};
