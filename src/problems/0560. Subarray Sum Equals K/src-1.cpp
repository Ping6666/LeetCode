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
    // Runtime: 53 ms (Beats 93.92 %), Memory: 44.91 MB (Beats 71.59 %).

public:
    int subarraySum(vector<int> &nums, int k)
    {
        int l = nums.size();
        unordered_map<int, int> table_nums;

        int hold = 0;
        int store_num, find_num;

        int ans = 0;

        for (int i = 0; i < l; i++)
        {
            store_num = -hold;
            table_nums[store_num]++;

            hold += nums[i];
            find_num = k - hold;

            if (table_nums.find(find_num) != table_nums.end())
            {
                ans += table_nums[find_num];
            }
        }

        return ans;
    }
};
