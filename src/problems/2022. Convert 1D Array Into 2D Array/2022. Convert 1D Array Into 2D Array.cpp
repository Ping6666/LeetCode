#include <vector>
using std::vector;

// Runtime: 71 ms (Beats 90.63 %), Memory: 99.90 MB (Beats 10.81 %).

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        int length = original.size();
        if (length != m * n)
        {
            return {};
        }

        vector<vector<int>> ans;
        int idx = 0;
        for (int i = 0; i < m; i++)
        {
            vector<int> vec;
            for (int j = 0; j < n; j++)
            {
                vec.push_back(original[idx]);
                idx++;
            }
            ans.push_back(vec);
        }

        return ans;
    }
};
