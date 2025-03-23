#include <stdio.h>
#include <vector>

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 8.99 MB (Beats 86.41 %).

public:
    int countTriplets(std::vector<int> &arr)
    {
        arr.insert(arr.begin(), 0);

        int l = arr.size();
        for (int i = 1; i < l; i++)
        {
            arr[i] ^= arr[i - 1];
        }

        int c = 0;

        for (int i = 0; i < l; i++)
        {
            for (int j = i + 1; j < l; j++)
            {
                if (arr[i] == arr[j])
                {
                    // if condition is true means that
                    // number in range i to j xor together will equals to 0
                    // which also means there will be `j - i - 1` triplets
                    c += j - i - 1;
                }
            }
        }

        // printf("ans: %d\n", c);
        return c;
    }
};

/*
class Solution
{
    // Runtime: 24 ms (Beats 19.38 %), Memory: 12.84 MB (Beats 5.79 %).

public:
    int countTriplets(std::vector<int> &arr)
    {
        int l = arr.size();
        std::vector<std::vector<int>> xor_table(l, std::vector<int>(l, 0));

        int i_bl;
        int i_tr;

        for (int shift = 0; shift < l; shift++)
        {
            for (int i = 0; i < l; i++)
            {
                // bottom-left
                i_bl = i - shift;
                if (i_bl >= 0)
                {
                    xor_table[i][i_bl] = arr[i_bl];
                    if (shift != 0)
                    {
                        xor_table[i][i_bl] ^= xor_table[i][i_bl + 1];
                    }
                }

                // top-right
                i_tr = i + shift + 1;
                if (i_tr < l)
                {
                    xor_table[i][i_tr] = arr[i_tr];
                    if (shift != 0)
                    {
                        xor_table[i][i_tr] ^= xor_table[i][i_tr - 1];
                    }
                }
            }
        }

        // for (int i = 0; i < l; i++)
        // {
        //     for (int j = 0; j < l; j++)
        //     {
        //         printf("%d ", xor_table[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");

        int c = 0;

        for (int i = 0; i < l; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                for (int k = i + 1; k < l; k++)
                {
                    if (xor_table[i][j] == xor_table[i][k])
                    {
                        c++;
                    }
                }
            }
        }

        // printf("ans: %d\n", c);
        return c;
    }
};
*/

int main()
{
    std::vector<int> arr;

    arr = {2, 3, 1, 6, 7};
    Solution().countTriplets(arr);

    arr = {1, 1, 1, 1, 1};
    Solution().countTriplets(arr);

    return 0;
}
