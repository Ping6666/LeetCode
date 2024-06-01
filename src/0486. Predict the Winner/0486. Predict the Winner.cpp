#include <stdio.h>

#include <vector>

using namespace std;

class Solution
{
    // Runtime: 0 ms (Beats 100 %), Memory: 7.4 MB (Beats 75.78 %).

public:
    bool PredictTheWinner(vector<int> &nums)
    {
        int n = nums.size();

        // init
        vector<int> dp_score(nums);

        for (int i = 1; i < n; i++)
        {
            // loop the pyramid

            for (int j = 0; j < n - i; j++)
            {
                // nums
                //   left  = j
                //   right = j + i
                // dp_score
                //   left  = j
                //   right = j + 1

                // use minuse because if first player take current value then
                //   the previous best value will be taken from the second player

                dp_score[j] = max(nums[j] - dp_score[j + 1], nums[j + i] - dp_score[j]);
            }
        }

        return dp_score[0] >= 0;
    }
};

int main()
{
    vector<int> nums;

    Solution s;
    bool ans;

    nums = {1, 5, 2};
    s = Solution();
    ans = s.PredictTheWinner(nums);
    printf("%d\n", ans);

    nums = {1, 5, 233, 7};
    s = Solution();
    ans = s.PredictTheWinner(nums);
    printf("%d\n", ans);

    return 0;
}
