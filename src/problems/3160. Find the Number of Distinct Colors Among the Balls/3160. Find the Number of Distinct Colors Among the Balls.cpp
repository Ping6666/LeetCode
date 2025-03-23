#include <vector>
#include <unordered_map>
using std::vector, std::unordered_map;

// Runtime: 104 ms (Beats 85.85 %), Memory: 157.42 MB (Beats 60.45 %).

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        unordered_map<int, int> idx_color;
        unordered_map<int, int> color_count;

        int p;
        vector<int> ans;
        for (const auto &q : queries)
        {
            if (idx_color.count(q[0]) != 0)
            {
                p = idx_color[q[0]];
                color_count[p]--;

                if (color_count[p] == 0)
                {
                    color_count.erase(p);
                }
            }

            idx_color[q[0]] = q[1];
            color_count[q[1]]++;

            ans.push_back(color_count.size());
        }
        return ans;
    }
};
