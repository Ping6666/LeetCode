#include <stdio.h>

#include <vector>
#include <bitset>
#include <limits> // numeric_limits

using namespace std;

void print2DVec(vector<vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            printf("%d ", vec[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*
class Solution
{
    vector<vector<int>> ans;

private:
    void helper(int n, int k, int start_num, vector<int> curr)
    {
        if (k == 0)
        {
            ans.push_back(curr);
            return;
        }

        for (int i = start_num; i <= n; i++)
        {
            vector<int> _curr(curr);
            _curr.push_back(i);
            helper(n, k - 1, i + 1, _curr);
        }

        return;
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        // return $C^n_k$

        vector<int> curr;
        helper(n, k, 1, curr);

        return ans;
    }
};
*/

class Solution
{
    // Runtime: 73 ms (Beats 20.84 %), Memory: 10.6 MB (Beats 41.48 %).

public:
    vector<vector<int>> combine(int n, int k)
    {
        // return $C^n_k$

        int count = 1 << n;
        const int n_bit = numeric_limits<int>::digits;

        vector<vector<int>> ans;
        vector<int> curr;

        for (int i = 0; i < count; i++)
        {
            int num = i, j = 0;
            curr = vector<int>();

            bitset<n_bit> bs(num);
            if (bs.count() != k)
            {
                continue;
            }

            while (num > 0)
            {
                if (num % 2)
                {
                    curr.push_back(j + 1);
                }

                num /= 2;
                j++;
            }

            ans.push_back(curr);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> ans;

    s = Solution();
    ans = s.combine(4, 2);
    print2DVec(ans);

    s = Solution();
    ans = s.combine(1, 1);
    print2DVec(ans);

    return 0;
}
