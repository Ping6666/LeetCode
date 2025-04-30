#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 10.35 MB (Beats 22.37 %).

class Solution
{
private:
    void parse(const vector<int> &nums, const int idx, vector<int> &xors)
    {
        if (nums.size() == idx)
        {
            return;
        }

        const int n = xors.size();
        for (int i = 0; i < n; i++)
        {
            xors.push_back(xors[i] ^ nums[idx]);
        }
        xors.push_back(nums[idx]);

        return parse(nums, idx + 1, xors);
    }

public:
    int subsetXORSum(vector<int> &nums)
    {
        vector<int> xors;
        parse(nums, 0, xors);
        int ans = 0;
        for (const auto x : xors)
        {
            ans += x;
        }
        return ans;
    }
};
