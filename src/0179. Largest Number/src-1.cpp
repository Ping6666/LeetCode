#include <vector>
#include <string>
#include <algorithm>
using std::vector, std::string, std::to_string, std::sort;

// fail with case
// [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> idx(n, 0);
        vector<string> str_nums;

        for (int i = 0; i < n; i++)
        {
            idx[i] = i;
            str_nums.push_back(to_string(nums[i]));
        }

        auto cmp = [&](int lhs, int rhs)
        {
            if (nums[lhs] == nums[rhs])
            {
                return true;
            }

            int lhs_n = str_nums[lhs].size(), rhs_n = str_nums[rhs].size();
            int lhs_i = 0, rhs_i = 0;

            while (true)
            {
                if (str_nums[lhs][lhs_i] != str_nums[rhs][rhs_i])
                {
                    return str_nums[lhs][lhs_i] > str_nums[rhs][rhs_i];
                }

                lhs_i = (lhs_i + 1) % lhs_n;
                rhs_i = (rhs_i + 1) % rhs_n;
            }
        };

        sort(idx.begin(), idx.end(), cmp);

        string ans = "";
        for (int i = 0; i < n; i++)
        {
            // printf("%d %s\n", idx[i], str_nums[idx[i]].c_str());
            if (str_nums[idx[i]][0] == '0' && ans[0] == '0')
            {
                break;
            }

            ans += str_nums[idx[i]];
        }

        return ans;
    }
};
