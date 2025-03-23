#include <vector>
#include <string>
#include <algorithm>
using std::vector, std::string, std::to_string, std::sort;

// Runtime: 0 ms (Beats 100.00 %), Memory: 17.32 MB (Beats 36.02 %).

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> str_nums;

        for (const auto &n : nums)
        {
            str_nums.push_back(to_string(n));
        }

        sort(str_nums.begin(), str_nums.end(), [&](const string &lhs, const string &rhs)
             { return lhs + rhs > rhs + lhs; });

        if (str_nums[0] == "0")
        {
            return "0";
        }

        string ans = "";
        for (const auto &s : str_nums)
        {
            ans += s;
        }

        return ans;
    }
};
