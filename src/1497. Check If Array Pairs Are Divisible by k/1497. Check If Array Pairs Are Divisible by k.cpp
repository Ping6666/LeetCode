#include <vector>
using std::vector;

// Runtime: 75 ms (Beats 93.12 %), Memory: 64.18 MB (Beats 96.96 %).

class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (n % 2 == 1)
        {
            return false;
        }

        vector<int> table(k, 0);
        for (int i = 0; i < n; i++)
        {
            arr[i] %= k;
            if (arr[i] < 0)
            {
                arr[i] += k;
            }
            table[arr[i]]++;
            // printf("%d\n", arr[i]);
        }

        // printf("\n");
        // for (int i = 0; i < k; i++)
        // {
        //     printf("%d\n", table[i]);
        // }

        // printf("\n");
        // for (int i = 1; (i < (!(k % 2) ? k / 2 : k / 2 + 1)); i++)
        // {
        //     printf("%d\n", i);
        // }

        bool check = !(table[0] % 2);
        if (!(k % 2) && check)
        {
            check = !(table[k / 2] % 2);
        }

        for (int i = 1; (i < (!(k % 2) ? k / 2 : k / 2 + 1)) && check; i++)
        {
            check = (table[i] == table[k - i]);
        }

        return check;
    }
};
