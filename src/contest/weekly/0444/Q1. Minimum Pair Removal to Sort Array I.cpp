#include <vector>
using std::vector;

class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        int op_count = 0;
        while (true)
        {
            const int n = nums.size();

            if (n == 1)
            {
                return op_count;
            }

            int min_pair = INT_MAX; // got BUG here...
            int min_pair_idx = 0;

            bool checker = true;
            for (int i = 1; i < n; i++)
            {
                if (nums[i] < nums[i - 1])
                {
                    checker = false;
                }

                int _pair = nums[i] + nums[i - 1];
                if (_pair < min_pair)
                {
                    min_pair = _pair;
                    min_pair_idx = i - 1;
                }
            }
            if (checker)
            {
                return op_count;
            }

            // op

            op_count++;
            nums[min_pair_idx] = min_pair;
            // nums[min_pair_idx + 1] = min_pair;
            nums.erase(nums.begin() + min_pair_idx + 1);

            // for (const auto nn : nums)
            // {
            //     printf("%d ", nn);
            // }
            // printf("\n");
        }
        return op_count;
    }
};
