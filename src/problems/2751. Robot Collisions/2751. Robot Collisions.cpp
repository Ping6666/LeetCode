#include <vector>
#include <string>
#include <algorithm>
using std::vector, std::string, std::sort;

// Runtime: 177 ms (Beats 97.71 %), Memory: 195.86 MB (Beats 87.79 %).
// sort and keep the indice!

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int n = positions.size();

        vector<int> indices(n), left, right, ans;

        for (int i = 0; i < n; i++)
        {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int lhs, int rhs)
             { return positions[lhs] < positions[rhs]; });

        int idx, r_idx;
        for (int i = 0; i < n; i++)
        {
            idx = indices[i];
            if (directions[idx] == 'R')
            {
                right.push_back(idx);
            }
            else
            {
                if (right.empty())
                {
                    left.push_back(idx);
                }
                else
                {
                    while (!right.empty())
                    {
                        r_idx = right.back();
                        if (healths[r_idx] < healths[idx])
                        {
                            right.pop_back();
                            healths[r_idx] = 0;
                            healths[idx]--;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (right.empty())
                    {
                        left.push_back(idx);
                    }
                    else
                    {
                        if (healths[r_idx] > healths[idx])
                        {
                            healths[r_idx]--;
                            healths[idx] = 0;
                        }
                        else
                        {
                            right.pop_back();
                            healths[r_idx] = 0;
                            healths[idx] = 0;
                        }
                    }
                }
            }
        }

        // use ori. indices take out the ans.
        for (int i = 0; i < n; i++)
        {
            if (healths[i] > 0)
            {
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};
