#include <vector>
using std::vector;

// Runtime: 86 ms (Beats 87.78 %), Memory: 76.73 MB (Beats 59.37 %).

class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        long long chalk_sum = 0;
        for (const auto &c : chalk)
        {
            chalk_sum += c;
        }

        k %= chalk_sum;
        for (int i = 0; i < chalk.size(); i++)
        {
            if (k < chalk[i])
            {
                return i;
            }
            k -= chalk[i];
        }

        return chalk.size() - 1;
    }
};
