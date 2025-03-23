#include <vector>
using std::vector;

// Runtime: 31 ms (Beats 67.12 %), Memory: 11.64 MB (Beats 51.74 %).

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int n = rating.size();

        int teams = 0;
        int as_l, as_r, des_l, des_r;

        for (int i = 1; i < n - 1; i++)
        {
            as_l = 0, as_r = 0, des_l = 0, des_r = 0;
            for (int j = 0; j < n; j++)
            {
                if (j < i)
                {
                    if (rating[j] > rating[i])
                    {
                        des_l++;
                    }
                    else if (rating[j] < rating[i])
                    {
                        as_l++;
                    }
                }
                else if (j > i)
                {
                    if (rating[j] > rating[i])
                    {
                        as_r++;
                    }
                    else if (rating[j] < rating[i])
                    {
                        des_r++;
                    }
                }
            }
            teams += as_l * as_r + des_l * des_r;
        }

        return teams;
    }
};
