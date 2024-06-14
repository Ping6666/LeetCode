#include <vector>
using std::vector;

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 9.75 MB (Beats 71.79 %).
    // In order to solve the follow up
    //   with a one-pass algorithm using only constant extra space

public:
    void sortColors(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;

        int swap_n, last_i_1 = -1, last_j_1 = -1;
        while (i < j)
        {
            //  i   0 1 2
            // j  0 x   o
            // j  1 x
            // j  2 x x x

            if (nums[i] == 0)
            {
                if (last_i_1 != -1)
                {
                    swap_n = nums[i];
                    nums[i] = nums[last_i_1];
                    nums[last_i_1] = swap_n;

                    last_i_1++;
                }

                i++;
                continue;
            }
            if (nums[j] == 2)
            {
                if (last_j_1 != -1)
                {
                    swap_n = nums[j];
                    nums[j] = nums[last_j_1];
                    nums[last_j_1] = swap_n;

                    last_j_1--;
                }

                j--;
                continue;
            }

            if (nums[i] == 2 && nums[j] == 0)
            {
                if (last_i_1 != -1 && last_j_1 != -1)
                {
                    nums[last_i_1] = 0;
                    nums[last_j_1] = 2;

                    nums[i] = 1;
                    nums[j] = 1;

                    last_i_1++;
                    last_j_1--;
                }
                else if (last_i_1 != -1)
                {
                    nums[last_i_1] = 0;

                    nums[i] = 1;
                    nums[j] = 2;

                    last_i_1++;
                }
                else if (last_j_1 != -1)
                {
                    nums[last_j_1] = 2;

                    nums[i] = 0;
                    nums[j] = 1;

                    last_j_1--;
                }
                else
                {
                    swap_n = nums[i];
                    nums[i] = nums[j];
                    nums[j] = swap_n;
                }

                i++;
                j--;
                continue;
            }

            if (nums[j] == 0)
            {
                // i will be 1

                if (last_i_1 != -1)
                {
                    swap_n = nums[j];
                    nums[j] = nums[last_i_1];
                    nums[last_i_1] = swap_n;

                    // j--;
                    last_i_1++;
                }
                else
                {
                    swap_n = nums[j];
                    nums[j] = nums[i];
                    nums[i] = swap_n;
                    i++;
                }
            }
            else if (nums[i] == 2)
            {
                // j will be 1

                if (last_j_1 != -1)
                {
                    swap_n = nums[i];
                    nums[i] = nums[last_j_1];
                    nums[last_j_1] = swap_n;

                    // i++;
                    last_j_1--;
                }
                else
                {
                    swap_n = nums[i];
                    nums[i] = nums[j];
                    nums[j] = swap_n;
                    j--;
                }
            }
            else
            {
                // both i & j to be 1
                if (last_i_1 == -1)
                {
                    last_i_1 = i;
                }

                if (last_j_1 == -1)
                {
                    last_j_1 = j;
                }

                i++;
                j--;
            }
        }

        if (i == j)
        {
            if (nums[i] == 0)
            {
                if (last_i_1 != -1)
                {
                    swap_n = nums[i];
                    nums[i] = nums[last_i_1];
                    nums[last_i_1] = swap_n;

                    // last_i_1++;
                }
            }
            else if (nums[i] == 2)
            {
                if (last_j_1 != -1)
                {
                    swap_n = nums[j];
                    nums[j] = nums[last_j_1];
                    nums[last_j_1] = swap_n;

                    // last_j_1--;
                }
            }
        }
    }
};
