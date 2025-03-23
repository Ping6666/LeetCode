#include <vector>
#include <string>
#include <unordered_set>
using std::vector, std::string, std::unordered_set;

// Runtime: 10 ms (Beats 93.63 %), Memory: 17.85 MB (Beats 91.51 %).

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_set<string> one_table, two_table;

        for (const auto &a : arr)
        {
            if (two_table.find(a) == two_table.end())
            {
                // 0 or 1

                if (one_table.find(a) == one_table.end())
                {
                    // 0
                    one_table.insert(a);
                }
                else
                {
                    // 1
                    one_table.erase(a);
                    two_table.insert(a);
                }
            }
        }

        int j = 0;
        for (const auto &a : arr)
        {
            if (one_table.find(a) != one_table.end())
            {
                // hit
                if (++j == k)
                {
                    return a;
                }
            }
        }

        return "";
    }
};
