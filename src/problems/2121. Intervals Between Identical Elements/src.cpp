#include <vector>
#include <unordered_map>
#include <iostream>
using std::vector, std::unordered_map;

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
    // Runtime: 183 ms (Beats 95.43 %), Memory: 132.36 MB (Beats 62.10 %).
    // Time Complexity: O(3*N), Space Complexity: O(N)

public:
    vector<long long> getDistances(vector<int> &arr)
    {
        int l = arr.size();
        vector<long long> table(l, 0);

        unordered_map<int, vector<int>> value_idx_map;
        // the value in arr map to all idx that got same value

        for (int i = 0; i < l; i++)
        {
            value_idx_map[arr[i]].push_back(i);
        }

        long long l_sum, l_len, r_sum, r_len;

        for (auto t : value_idx_map)
        {
            r_len = t.second.size();
            if (r_len == 1)
            {
                // only one curr. value in the arr
                continue;
            }

            l_sum = l_len = r_sum = 0;
            for (auto idx : t.second)
            {
                r_sum += idx;
            }

            for (auto idx : t.second)
            {
                table[idx] = (r_sum - (r_len * idx)) + ((l_len * idx) - l_sum);
                l_sum += idx;
                l_len++;
                r_sum -= idx;
                r_len--;
            }
        }

        return table;
    }
};
