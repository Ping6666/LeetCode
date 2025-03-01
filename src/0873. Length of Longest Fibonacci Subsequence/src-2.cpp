#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map, std::max;

// Runtime: 235 ms (Beats 83.33 %), Memory: 15.53 MB (Beats 87.82 %).

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        const int n = arr.size();

        unordered_map<int, int> table;
        for (int i = 0; i < n; i++)
        {
            table[arr[i]] = i;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1, next_num = -1, prev_j, l; j < n;)
            {
                // pruning
                if (ans > (l + n - j))
                {
                    break;
                }

                if (next_num == -1)
                {
                    prev_j = j;
                    next_num = arr[i] + arr[j];
                    l = 2;

                    // // another pruning
                    // if (table.find(next_num) == table.end())
                    // {
                    //     j = prev_j + 1;
                    //     l = 0;
                    //     next_num = -1;
                    // }
                }
                else
                {
                    if (table.find(next_num) != table.end())
                    {
                        // hit
                        int jj = j;
                        j = table[next_num];
                        next_num = arr[jj] + arr[j];
                        l++;
                    }
                    else
                    {
                        if (l >= 3)
                        {
                            ans = max(ans, l);
                        }

                        j = prev_j + 1;
                        l = 0;
                        next_num = -1;
                    }
                }
            }
        }
        return ans;
    }
};
