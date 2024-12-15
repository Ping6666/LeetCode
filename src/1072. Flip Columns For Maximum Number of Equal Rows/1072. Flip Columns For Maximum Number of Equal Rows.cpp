#include <vector>
#include <string>
#include <unordered_map>
using std::vector, std::string, std::unordered_map;

// Runtime: 17 ms (Beats 83.33 %), Memory: 74.39 MB (Beats 75.00 %).

// ref.: LeetCode Editorial - Approach 2: Hash Map

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        unordered_map<string, int> table;

        for (const auto &row : matrix)
        {
            string str = "";

            for (const auto &c : row)
            {
                if (c == row[0])
                {
                    str += 'T';
                }
                else
                {
                    str += 'F';
                }
            }

            table[str]++;
        }

        int ans = 0;
        for (const auto &t : table)
        {
            ans = max(ans, t.second);
        }

        return ans;
    }
};
