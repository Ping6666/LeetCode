#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 12.26 MB (Beats 42.46 %).

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        int freq[1000] = {0};
        for (const auto ans : answers)
        {
            freq[ans]++;
        }

        int ans = freq[0];
        for (int i = 1; i < 1000; i++)
        {
            if (freq[i] == 0)
            {
                continue;
            }

            while (freq[i] > 0)
            {
                ans += i + 1;
                freq[i] -= (i + 1);
            }
        }
        return ans;
    }
};
