#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 95.33 MB (Beats 82.32 %).

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int n = nums.size();
        int _xor = pow(2, maximumBit) - 1;

        vector<int> xor_table(n, 0);
        xor_table[n - 1] = nums[0];
        // printf("%d\n", xor_table[n - 1]);

        for (int i = 1; i < n; i++)
        {
            xor_table[n - i - 1] = xor_table[n - i] ^ nums[i];
            xor_table[n - i] ^= _xor;

            // printf("%d\n", xor_table[n - i - 1]);
        }
        xor_table[0] ^= _xor;

        return xor_table;
    }
};
