#include <vector>
#include <algorithm>
using std::vector, std::sort;

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 14.72 MB (Beats 70.42 %).

public:
    vector<int> frequencySort(vector<int> &nums)
    {
        int n = nums.size();

        int freq[201] = {};
        for (int i = 0; i < n; i++)
        {
            freq[nums[i] + 100]++;
        }

        sort(nums.begin(), nums.end(), [&](int lhs, int rhs)
             { return freq[lhs + 100] != freq[rhs + 100] ? freq[lhs + 100] < freq[rhs + 100] : lhs > rhs; });

        return nums;
    }
};

class Solution
{
    // Runtime: 3 ms (Beats 89.91 %), Memory: 15.35 MB (Beats 5.99 %).

public:
    vector<int> frequencySort(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> freq(201);
        vector<int> freq_indices(201);

        for (int i = 0; i < 201; i++)
        {
            freq_indices[i] = i;
        }

        for (int i = 0; i < n; i++)
        {
            freq[nums[i] + 100]++;
        }

        sort(freq_indices.begin(), freq_indices.end(), [&](int lhs, int rhs)
             { return freq[lhs] != freq[rhs] ? freq[lhs] < freq[rhs] : lhs > rhs; });

        vector<int> ans;
        for (int i = 0; i < 201; i++)
        {
            for (int j = 0; j < freq[freq_indices[i]]; j++)
            {
                ans.push_back(freq_indices[i] - 100);
            }
        }

        return ans;
    }
};
