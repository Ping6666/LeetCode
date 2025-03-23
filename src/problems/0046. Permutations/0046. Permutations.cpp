#include <stdio.h>

#include <list>
#include <vector>

using namespace std;

void print2DVec(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            printf("%d ", vec[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

class Solution
{
    // Runtime: 3 ms (Beats 67.29 %), Memory: 7.8 MB (Beats 46.70 %).

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return vector<vector<int>>(1, nums);
        }

        vector<vector<int>> ans(1, vector<int>(1, nums[0]));

        for (int i = 1; i < n; i++)
        {
            while (true)
            {
                vector<int> f = ans.front();
                int f_len = f.size();

                if (f_len == i + 1)
                {
                    break;
                }
                else
                {
                    ans.erase(ans.begin());
                    for (int j = 0; j <= f_len; j++)
                    {
                        vector<int> tmp(f);
                        tmp.insert(tmp.begin() + j, nums[i]);

                        ans.push_back(tmp);
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums;

    Solution s;
    vector<vector<int>> ans;

    nums = {1, 2, 3};
    s = Solution();
    ans = s.permute(nums);
    print2DVec(ans);

    nums = {0, 1};
    s = Solution();
    ans = s.permute(nums);
    print2DVec(ans);

    nums = {1};
    s = Solution();
    ans = s.permute(nums);
    print2DVec(ans);

    return 0;
}
