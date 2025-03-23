#include <vector>
#include <string>
#include <algorithm>
using std::vector, std::string, std::sort;

// Runtime: 16 ms (Beats 97.91 %), Memory: 22.66 MB (Beats 85.55 %).

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        int n = names.size();

        vector<int> indices(n);
        for (int i = 0; i < n; i++)
        {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&](int lhs, int rhs)
             { return heights[lhs] > heights[rhs]; });

        vector<string> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = names[indices[i]];
        }

        return ans;
    }
};
