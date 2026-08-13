#include <vector>
#include <unordered_map>

using std::vector, std::unordered_map;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;

        int c = 0, r;
        for (int i = 0; i < nums.size(); i++)
        {
            r = k - nums[i];
            if (m.find(r) != m.end() && m[r] > 0)
            {
                m[r]--;
                c++;
            }
            else
            {
                m[nums[i]]++;
            }
        }
        return c;
    }
};