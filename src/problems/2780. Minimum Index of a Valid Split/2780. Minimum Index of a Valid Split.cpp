#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map;

// Runtime: 31 ms (Beats 60.25 %), Memory: 98.39 MB (Beats 62.30 %).

// ToDo
// use Boyer–Moore majority vote algorithm to speed up

class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        unordered_map<int, int> num_freq;
        for (const auto &n : nums)
        {
            num_freq[n]++;
        }

        int x = -1, x_count = 0;
        for (const auto &n : num_freq)
        {
            if (n.second > x_count)
            {
                x = n.first;
                x_count = n.second;
            }
        }

        const int l = nums.size();
        int curr_count = 0;
        for (int i = 0; i < l - 1; i++)
        {
            if (nums[i] == x)
            {
                curr_count++;
            }

            if ((curr_count * 2 > (i + 1)) && (x_count - curr_count) * 2 > (l - i - 1))
            {
                return i;
            }
        }
        return -1;
    }
};
