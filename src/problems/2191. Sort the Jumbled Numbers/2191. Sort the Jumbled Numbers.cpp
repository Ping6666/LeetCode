#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 262 ms (Beats 61.47 %), Memory: 77.24 MB (Beats 93.94 %).

int num_map(vector<int> &mapping, int n)
{
    int m = 0, r = 1;

    // printf("%d -> ", n);

    if (n == 0)
    {
        return mapping[0];
    }

    while (n > 0)
    {
        m += mapping[n % 10] * r;

        n /= 10;
        r *= 10;
    }

    // printf("%d\n", m);

    return m;
}

class Solution
{
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        int n = nums.size();

        vector<int> table(n);
        for (int i = 0; i < n; i++)
        {
            table[i] = num_map(mapping, nums[i]);
        }

        vector<int> indices(n);
        for (int i = 0; i < n; i++)
        {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&](int lhs, int rhs)
             { return table[lhs] < table[rhs]; });

        for (int i = 0; i < n; i++)
        {
            table[i] = nums[indices[i]];
        }

        return table;
    }
};
