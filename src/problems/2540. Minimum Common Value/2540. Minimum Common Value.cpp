#include <vector>
#include <iostream>
using std::vector;

class Solution
{
    // with magic
    //   Runtime: 19 ms (Beats 99.78 %), Memory: 52.54 MB (Beats 99.78 %).

    // without magic
    //   Runtime: 64 ms (Beats 74.52 %), Memory: 52.87 MB (Beats 89.25 %).

public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        // Both nums1 and nums2 are sorted in non-decreasing order.

        // magic
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);

        int i1 = 0, i2 = 0;
        int l1 = nums1.size(), l2 = nums2.size();

        while (i1 < l1 && i2 < l2)
        {
            if (nums1[i1] == nums2[i2])
            {
                return nums1[i1];
            }
            else if (nums1[i1] > nums2[i2])
            {
                i2++;
            }
            else if (nums1[i1] < nums2[i2])
            {
                i1++;
            }
        }

        return -1;
    }
};
