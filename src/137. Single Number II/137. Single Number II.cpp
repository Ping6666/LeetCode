#include <vector>
using std::vector;

class Solution
{
    // Runtime: 2 ms (Beats 92.13 %), Memory: 11.67 MB (Beats 96.97 %).
    // Time Complexity: O(N), Space Complexity: O(1)

public:
    int singleNumber(vector<int> &nums)
    {
        // track each bit appears once or twice
        int once = 0, twice = 0;

        for (auto n : nums)
        {
            once = (once ^ n) & (~twice);
            // once ^ n: keep track on bit appears once
            // & (~twice): remove those bits that appear twice

            twice = (twice ^ n) & (~once);
            // twice ^ n: keep track on bit appears twice
            // & (~once): remove those bits that appear once
        }

        // bit appear 1-st time; once: 0 -> 1, twice: 0 -> 0.
        // bit appear 2-nd time; once: 1 -> 0, twice: 0 -> 1.
        // bit appear 3-rd time; once: 0 -> 0, twice: 1 -> 0.
        // bit appear 4-th time; once: 0 -> 1, twice: 0 -> 0. dup. with / loop back to 1-st

        return once;
    }
};

/*
class Solution
{
    // Runtime: 4 ms (Beats 79.68 %), Memory: 11.73 MB (Beats 82.44 %).
    // Time Complexity: O(32N), Space Complexity: O(1)

public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;

        int counter;

        // loop all bits
        for (int i = 0; i < 32; i++)
        {
            counter = 0;

            for (auto n : nums)
            {
                counter += n >> i & 1;
            }

            counter %= 3;
            // counter will be either 0 or 1

            ans += counter << i;
        }

        return ans;
    }
};
*/
