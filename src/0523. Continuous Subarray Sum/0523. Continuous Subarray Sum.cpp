#include <vector>
#include <unordered_set>
#include <iostream>
using std::vector, std::unordered_set;

// Runtime: 125 ms (Beats 98.30 %), Memory: 134.53 MB (Beats 86.97 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

int positive_mod(int n, int k)
{
    n = n % k;
    if (n >= 0)
    {
        return n;
    }
    return (n % k + k) % k;
}

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int l = nums.size();
        unordered_set<int> table_nums;

        table_nums.insert(positive_mod(nums[0], k));

        int hold = 0;
        int store_num, find_num;

        for (int i = 1; i < l; i++)
        {
            store_num = positive_mod(-hold, k);
            hold = positive_mod((hold + (nums[i] % k)), k);
            find_num = positive_mod(-hold, k);

            if (table_nums.find(find_num) != table_nums.end())
            {
                return true;
            }

            table_nums.insert(store_num);
        }

        return false;
    }
};
