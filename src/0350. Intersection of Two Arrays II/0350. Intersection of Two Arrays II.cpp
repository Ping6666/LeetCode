#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 0 ms (Beats 100.00 %), Memory: 12.44 MB (Beats 91.17 %).

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int l1 = nums1.size(), l2 = nums2.size();
        int i1 = 0, i2 = 0;

        vector<int> ans;
        while (i1 < l1 && i2 < l2)
        {
            if (nums1[i1] == nums2[i2])
            {
                ans.push_back(nums1[i1]);
                i1++, i2++;
            }
            else if (nums1[i1] > nums2[i2])
            {
                i2++;
            }
            else
            {
                i1++;
            }
        }

        return ans;
    }
};
