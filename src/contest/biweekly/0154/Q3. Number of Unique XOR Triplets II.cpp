#include <vector>
#include <unordered_set>
using std::vector, std::unordered_set;

// TLE

class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        // /*
        const int n = nums.size();
        // vector<vector<int>> table(n, vector<int>(n, -1));

        unordered_set<int> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // if (table[i][j] == -1)
                // {
                //     table[i][j] = nums[i] ^ nums[j];
                // }

                for (int k = j; k < n; k++)
                {
                    // ans.insert(table[i][j] ^ nums[k]);
                    ans.insert(nums[i] ^ nums[j] ^ nums[k]);
                }
            }
        }
        // return ans.size();
        // */

        int nn = nums[0];
        for (const int num : nums)
        {
            nn |= num;
        }
        printf("%d\n", nn);

        int bits_count = 0;
        while (nn > 0)
        {
            if (nn % 2 == 1)
            {
                bits_count++;
            }
            nn /= 2;
        }
        printf("%d\n", bits_count);

        return ans.size();
        // return 0;
    }
};
