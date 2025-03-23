#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.99 MB (Beats 91.69 %).

class Solution
{
private:
    vector<int> getAllPossibleSum(const int &arr_len, const vector<int> &arr, int prev, int curr)
    {
        int curr_num = 0;
        for (int i = prev; i < curr; i++)
        {
            curr_num *= 10;
            curr_num += arr[arr_len - 1 - i];
        }

        if (curr == arr_len)
        {
            return {curr_num};
        }

        vector<int> vec1 = getAllPossibleSum(arr_len, arr, curr, curr + 1);
        vector<int> vec2 = getAllPossibleSum(arr_len, arr, prev, curr + 1);

        for (int &n : vec1)
        {
            n += curr_num;
        }

        vector<int> ans;
        for (const auto &n : vec1)
        {
            ans.push_back(n);
        }
        for (const auto &n : vec2)
        {
            ans.push_back(n);
        }

        return ans;
    }

    bool isPunishmentNumber(int n)
    {
        int n2 = n * n;
        int n2_copy = n2;

        vector<int> arr;
        while (n2_copy > 0)
        {
            arr.push_back(n2_copy % 10);
            n2_copy /= 10;
        }

        vector<int> ans = getAllPossibleSum(arr.size(), arr, 0, 1);
        // printf("%d: ", n);
        for (const auto &a : ans)
        {
            // printf("%d ", a);
            if (a == n)
            {
                return true;
            }
        }
        // printf("\n");

        return false;
    }

public:
    int punishmentNumber(int n)
    {
        // for (int i = 1; i <= 1000; i++)
        // {
        //     if (isPunishmentNumber(i))
        //     {
        //         printf("%d, ", i);
        //     }
        // }
        // printf("\n");
        vector<int> table = {1, 9, 10, 36, 45, 55, 82, 91, 99, 100, 235, 297, 369, 370, 379, 414, 657, 675, 703, 756, 792, 909, 918, 945, 964, 990, 991, 999, 1000};

        int ans = 0;
        for (const auto &t : table)
        {
            if (t <= n)
            {
                ans += t * t;
            }
        }

        return ans;
    }
};
