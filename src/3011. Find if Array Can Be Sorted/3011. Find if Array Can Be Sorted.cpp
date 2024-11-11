#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 0 ms (Beats 100.00 %), Memory: 31.50 MB (Beats 48.14 %).

int getNumOne(int n)
{
    int ans = 0;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans++;
        }
        n /= 2;
    }

    return ans;
}

class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        int n = nums.size();

        int counter = 0, bit_mask = 0;

        for (int i = 0; i < n; i++)
        {
            if (counter != 0 && bit_mask == getNumOne(nums[i]))
            {
                counter++;
            }
            else
            {
                // printf("\n");
                // printf("%d %d %d\n", i, counter, i - counter);
                if (counter > 1)
                {
                    // do sort
                    sort(nums.begin() + i - counter, nums.begin() + i);
                }

                if (i - counter - 1 >= 0)
                {
                    // printf("%d %d\n", nums[i - counter - 1], nums[i - counter]);
                    if (nums[i - counter - 1] > nums[i - counter])
                    {
                        return false;
                    }
                }

                counter = 1;
                bit_mask = getNumOne(nums[i]);
            }
        }

        // printf("\n");
        // printf("%d %d %d\n", n, counter, n - counter);
        if (counter > 1)
        {
            // do sort
            sort(nums.begin() + n - counter, nums.begin() + n);
        }

        if (n - counter - 1 >= 0)
        {
            // printf("%d %d\n", nums[n - counter - 1], nums[n - counter]);
            if (nums[n - counter - 1] > nums[n - counter])
            {
                return false;
            }
        }

        return true;
    }
};
