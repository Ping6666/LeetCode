#include <vector>

using std::vector;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int len = candies.size();
        int max_candy = candies[0];
        for (int i = 1; i < len; i++)
        {
            max_candy = std::max(max_candy, candies[i]);
        }

        vector<bool> ans = vector<bool>(len);
        for (int i = 0; i < len; i++)
        {
            ans[i] = (candies[i] >= (max_candy - extraCandies)) ? true : false;
        }
        return ans;
    }
};
