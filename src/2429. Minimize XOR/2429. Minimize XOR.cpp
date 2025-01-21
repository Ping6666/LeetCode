
// Runtime: 0 ms (Beats 100.00 %), Memory: 7.89 MB (Beats 85.98 %).

class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int n1 = 0, n2 = 0;
        int arr[30] = {0}; // 1e9
        for (int i = 0; i < 30; i++)
        {
            if ((num1 >> i) & 1 == 1)
            {
                n1++;
                arr[i] = 1;
            }
            if ((num2 >> i) & 1 == 1)
            {
                n2++;
            }
        }

        if (n1 == n2)
        {
            return num1;
        }

        int ans = num1;
        if (n1 < n2)
        {
            // need add 1
            for (int i = n1, idx = 0; i < n2; i++)
            {
                while (arr[idx] == 1)
                {
                    idx++;
                }
                ans += (1 << idx);
                idx++;
            }
        }
        else
        {
            // need remove 1
            for (int i = n2, idx = 0; i < n1; i++)
            {
                while (arr[idx] == 0)
                {
                    idx++;
                }
                ans -= (1 << idx);
                idx++;
            }
        }

        return ans;
    }
};
