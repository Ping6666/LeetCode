#include <vector>
using std::vector;

// Runtime: 47 ms (Beats 92.65 %), Memory: 41.67 MB (Beats 84.53 %).

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            arr[i + 1] ^= arr[i];
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            if (queries[i][0] != 0)
            {
                ans.push_back(arr[queries[i][0] - 1] ^ arr[queries[i][1]]);
            }
            else
            {
                ans.push_back(arr[queries[i][1]]);
            }
        }

        return ans;
    }
};
