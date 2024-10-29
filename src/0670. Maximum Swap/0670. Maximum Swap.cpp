// Runtime: 0 ms (Beats 100.00 %), Memory: 7.48 MB (Beats 89.76 %).

class Solution
{
public:
    int maximumSwap(int num)
    {
        if (num <= 10)
        {
            return num;
        }

        int arr[10] = {};
        int len = 0;

        while (num > 0)
        {
            arr[len++] = num % 10;
            num /= 10;
        }

        //

        for (int i = len - 1; i > 0; i--)
        {
            int max_j = i - 1;
            for (int j = i - 2; j >= 0; j--)
            {
                if (arr[max_j] <= arr[j])
                {
                    max_j = j;
                }
            }

            if (arr[i] < arr[max_j])
            {
                int t = arr[max_j];
                arr[max_j] = arr[i];
                arr[i] = t;
                break;
            }
        }

        int ans = 0;

        for (int i = len - 1; i >= 0; i--)
        {
            ans *= 10;
            ans += arr[i];
        }

        return ans;
    }
};
