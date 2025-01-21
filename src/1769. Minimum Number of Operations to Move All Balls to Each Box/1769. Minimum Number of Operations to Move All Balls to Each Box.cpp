#include <vector>
#include <string>
using std::vector, std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 11.96 MB (Beats 76.52 %).

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> ans(n, 0);

        int r_count = 0, r_sum = 0;
        int l_count = 0, l_sum = 0;

        for (int i = 1; i < n; i++)
        {
            if (boxes[i] == '1')
            {
                r_count++;
                r_sum += i - 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            ans[i] = l_sum + r_sum;

            if (i != n - 1 && boxes[i + 1] == '1')
            {
                r_count--;
                r_sum -= 1;
            }

            r_sum -= r_count;
            l_sum += l_count;

            if (boxes[i] == '1')
            {
                l_sum += 1;
                l_count++;
            }
        }

        return ans;
    }
};