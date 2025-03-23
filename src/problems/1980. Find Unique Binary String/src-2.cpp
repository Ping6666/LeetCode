#include <vector>
#include <string>
using std::vector, std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 12.42 MB (Beats 94.35 %).

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string ans = "";

        int i = 0;
        for (const auto &num : nums)
        {
            ans += num[i++] == '0' ? '1' : '0';
        }

        return ans;
    }
};
