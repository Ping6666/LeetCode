#include <vector>
using std::vector;

// Runtime: 15 ms (Beats 96.59 %), Memory: 34.22 MB (Beats 82.09 %).

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();

        int no_grumpy_sum = 0;
        int max_grumpy_sum = 0, curr_grumpy_sum = 0;

        for (int i = 0; i < minutes; i++)
        {
            if (!grumpy[i])
            {
                no_grumpy_sum += customers[i];
            }
            else
            {
                curr_grumpy_sum += customers[i];
                max_grumpy_sum = curr_grumpy_sum;
            }
        }

        for (int i = minutes; i < n; i++)
        {
            if (grumpy[i - minutes])
            {
                curr_grumpy_sum -= customers[i - minutes];
            }

            if (!grumpy[i])
            {
                no_grumpy_sum += customers[i];
            }
            else
            {
                curr_grumpy_sum += customers[i];

                if (curr_grumpy_sum > max_grumpy_sum)
                {
                    max_grumpy_sum = curr_grumpy_sum;
                }
            }
        }

        return no_grumpy_sum + max_grumpy_sum;
    }
};
