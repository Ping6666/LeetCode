#include <stdio.h>
#include <string.h> // memset

#include <vector>

using namespace std;

class Solution
{
    // Runtime: 87 ms (Beats 99.50 %), Memory: 49.2 MB (Beats 99.50 %).

public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        int k = 1e4;
        int dp[2 * k + 1];

        memset(dp, 0, sizeof(dp));

        int max_len = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            int curr_idx = k + arr[i];
            int prev_idx = k + arr[i] - difference;

            if (prev_idx >= 0 && prev_idx < 2 * k + 1)
            {
                dp[curr_idx] = dp[prev_idx] + 1;
            }
            else
            {
                dp[curr_idx] = 1;
            }

            max_len = max(max_len, dp[curr_idx]);
        }

        return max_len;
    }
};

/*
class Solution
{
    // Runtime: 251 ms (Beats 18.9 %), Memory: 60.7 MB (Beats 5.11 %).

public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        // given value map to the last show idx
        map<int, int> idx_map;
        map<int, int>::iterator it;

        int max_len = 0;
        vector<int> value_vec;

        int curr_val, prev_val;
        int new_max_len, curr_val_max_len, prev_val_max_len;

        for (int i = 0; i < arr.size(); i++)
        {
            curr_val = arr[i];
            prev_val = arr[i] - difference;

            // prev

            it = idx_map.find(prev_val);
            if (it == idx_map.end())
            {
                prev_val_max_len = 1;
            }
            else
            {
                prev_val_max_len = value_vec[it->second] + 1;
            }

            // curr & insert, update

            it = idx_map.find(curr_val);
            if (it == idx_map.end())
            {
                curr_val_max_len = 1;

                // insert
                pair<int, int> idx_pair{curr_val, i};
                idx_map.insert(idx_pair);
            }
            else
            {
                curr_val_max_len = value_vec[it->second];

                // update
                it->second = i;
            }

            // new

            new_max_len = max(prev_val_max_len, curr_val_max_len);
            value_vec.push_back(new_max_len);

            if (max_len < new_max_len)
            {
                max_len = new_max_len;
            }
        }

        return max_len;
    }
};
*/

int main()
{
    int difference;
    vector<int> vec;
    Solution s;
    int max_ret;

    difference = 1;
    vec = {1, 2, 3, 4};
    max_ret = s.longestSubsequence(vec, difference);
    printf("%d\n", max_ret);

    difference = 1;
    vec = {1, 3, 5, 7};
    max_ret = s.longestSubsequence(vec, difference);
    printf("%d\n", max_ret);

    difference = -2;
    vec = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    max_ret = s.longestSubsequence(vec, difference);
    printf("%d\n", max_ret);

    return 0;
}
