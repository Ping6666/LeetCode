#include <vector>
#include <unordered_map>
#include <iostream>
using std::vector, std::unordered_map;

// Runtime: 23 ms (Beats 97.81 %), Memory: 35.10 MB (Beats 63.15 %).

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
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int l = nums.size();
        unordered_map<int, int> table_nums;

        int hold = 0;
        int store_num, find_num;

        int ans = 0;

        for (int i = 0; i < l; i++)
        {
            store_num = positive_mod(-hold, k);
            table_nums[store_num]++;

            hold = positive_mod((hold + (nums[i] % k)), k);
            find_num = positive_mod(-hold, k);

            if (table_nums.find(find_num) != table_nums.end())
            {
                ans += table_nums[find_num];
            }
        }

        return ans;
    }
};
