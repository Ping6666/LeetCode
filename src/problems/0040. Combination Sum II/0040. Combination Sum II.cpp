#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 0 ms (Beats 100.00 %), Memory: 12.88 MB (Beats 58.11 %).

class Solution
{
private:
    void combination2(vector<int> &candidates, int remain, vector<vector<int>> &comb_sum, vector<int> &comb, int idx)
    {
        if (remain == 0)
        {
            comb_sum.push_back(comb);
        }

        for (int i = idx; i < candidates.size() && candidates[i] <= remain; i++)
        {
            if (i == idx || candidates[i] != candidates[i - 1])
            {
                comb.push_back(candidates[i]);
                combination2(candidates, remain - candidates[i], comb_sum, comb, i + 1);
                comb.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> comb_sum;
        vector<int> comb;

        combination2(candidates, target, comb_sum, comb, 0);
        return comb_sum;
    }
};
