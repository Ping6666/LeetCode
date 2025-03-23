#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 8.47 MB (Beats 87.88 %).
// ref.: LeetCode Editorial - Approach: Backtracking

class Solution
{
private:
    bool find(const int &n, vector<int> &ans, vector<bool> &used_num, int idx)
    {
        if (idx == 2 * n - 1)
        {
            return true;
        }

        if (ans[idx] != 0)
        {
            return find(n, ans, used_num, idx + 1);
        }

        for (int i = n; i >= 1; i--)
        {
            if (used_num[i])
            {
                continue;
            }

            used_num[i] = true;
            ans[idx] = i;

            if (i == 1)
            {
                if (find(n, ans, used_num, idx + 1))
                {
                    return true;
                }
            }
            else if (((idx + i) < (2 * n - 1)) && ans[idx + i] == 0)
            {
                ans[idx + i] = i;

                if (find(n, ans, used_num, idx + 1))
                {
                    return true;
                }

                ans[idx + i] = 0;
            }

            ans[idx] = 0;
            used_num[i] = false;
        }

        return false;
    }

public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> ans(2 * n - 1, 0);
        vector<bool> used_num(n + 1, false);

        find(n, ans, used_num, 0);

        return ans;
    }
};
