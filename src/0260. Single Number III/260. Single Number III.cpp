#include <vector>
using std::vector;

class Solution
{
    // Runtime: 5 ms (Beats 79.18 %), Memory: 12.24 MB (Beats 87.16 %).
    // Time Complexity: O(2N), Space Complexity: O(1)

public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int _xor = 0;
        int xor_0 = 0, xor_1 = 0;

        for (auto n : nums)
        {
            _xor ^= n;
        }

        // find first bit that is 1 in the _xor
        // this bit is the bit that
        //   1-st element that appear only once didnot got it (group xor_0), and
        //   2-nd element that appear only once dit    got it (group xor_1).
        // since the other elements will appear exactly twice no matter in which group,
        // therefore, those two elements that appear only once can be sep.

        int i = 0;
        while (((_xor >> i) & 1) != 1)
        {
            i++;
        }

        for (auto n : nums)
        {
            if (((n >> i) & 1) == 0)
            {
                xor_0 ^= n;
            }
            else
            {
                xor_1 ^= n;
            }
        }

        return {xor_0, xor_1};
    }
};
