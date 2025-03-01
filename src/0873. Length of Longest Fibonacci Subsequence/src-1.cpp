#include <vector>
using std::vector, std::max;

// TLE
// Time complexity: O( 2^n )

class Solution
{
private:
    void dfs(const vector<int> &arr, const int idx,
             vector<int> &fib_arr, int &ans)
    {
        const int n = arr.size();
        const int l = fib_arr.size();

        // printf("%d: ", l);
        // for (int j = 0; j < l; j++)
        // {
        //     printf("%d ", fib_arr[j]);
        // }
        // printf("\n");

        ans = max(ans, l >= 3 ? l : 0);

        if (idx == n)
        {
            return;
        }

        for (int i = idx; i < n; i++)
        {
            if (ans > (l + n - i))
            {
                continue;
            }

            if (l <= 1)
            {
                // l = 0 or 1

                fib_arr.push_back(arr[i]);
                dfs(arr, i + 1, fib_arr, ans);
            }
            else
            {
                // l = 2 or larger

                if (arr[i] == (fib_arr[l - 1] + fib_arr[l - 2]))
                {
                    fib_arr.push_back(arr[i]);
                    dfs(arr, i + 1, fib_arr, ans);
                }
                else
                {
                    continue;
                }
            }

            fib_arr.pop_back();
        }

        return;
    }

public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        vector<int> fib_arr;
        int ans = 0;

        dfs(arr, 0, fib_arr, ans);
        return ans;
    }
};
