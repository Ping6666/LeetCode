#include <vector>
using namespace std;

class Solution
{
    // Runtime: 0 ms (100.00 %), Memory: 8.6 MB (92.66 %).
public:
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.empty())
            return 0;
        int i = 0, ilast = nums.size();
        while (i < ilast)
        {
            while (nums[ilast - 1] == val)
            {
                ilast--;
                if (ilast <= i)
                {
                    return ilast;
                }
            }
            if (nums[i] == val)
            {
                if (i != ilast - 1)
                {
                    nums[i] = nums[ilast - 1];
                    ilast--;
                }
            }
            i++;
        }
        return ilast;
    }
};
