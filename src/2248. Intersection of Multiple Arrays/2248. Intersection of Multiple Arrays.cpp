#include <vector>
#include <set>
#include <algorithm>
using std::vector, std::set, std::set_intersection, std::inserter, std::find, std::sort;

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 13.92 MB (Beats 99.73 %).

public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        vector<int>::iterator it = nums[0].begin();
        vector<int>::iterator find_it;

        int l = nums[0].size();
        int j;

        for (int i = 1; i < nums.size(); i++)
        {
            j = 0;
            while (j < l)
            {
                find_it = find(nums[i].begin(), nums[i].end(), nums[0][j]);
                if (find_it == nums[i].end())
                {
                    // if not found `num[j]` in vector nums[i]
                    nums[0].erase(nums[0].begin() + j);
                    j--;
                    l--;
                }
                j++;
            }
        }

        sort(nums[0].begin(), nums[0].end());

        return nums[0];
    }
};

/*
class Solution
{
    // Runtime: 10 ms (Beats 51.41 %), Memory: 20.07 MB (Beats 5.38 %).

public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        set<int> table;
        set<int> tmp_table;
        set<int> swap_table;

        table.insert(nums[0].begin(), nums[0].end());

        for (int i = 0; i < nums.size(); i++)
        {
            tmp_table.insert(nums[i].begin(), nums[i].end());

            set_intersection(table.begin(), table.end(),
                             tmp_table.begin(), tmp_table.end(),
                             inserter(swap_table, swap_table.end()));

            table.clear();
            tmp_table.clear();

            table.insert(swap_table.begin(), swap_table.end());

            swap_table.clear();
        }

        vector<int> ans(table.begin(), table.end());

        return ans;
    }
};
*/
