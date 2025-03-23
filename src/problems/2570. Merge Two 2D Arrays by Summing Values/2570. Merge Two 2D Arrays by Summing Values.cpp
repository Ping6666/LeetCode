#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 14.60 MB (Beats 82.78 %).

class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        int len1 = nums1.size(), len2 = nums2.size();

        int idx1 = 0, idx2 = 0;
        vector<vector<int>> ans;

        while (idx1 < len1 && idx2 < len2)
        {
            if (nums1[idx1][0] == nums2[idx2][0])
            {
                // same id
                ans.push_back({nums1[idx1][0], nums1[idx1][1] + nums2[idx2][1]});
                idx1++;
                idx2++;
            }
            else if (nums1[idx1][0] < nums2[idx2][0])
            {
                // nums1 got smaller id
                ans.push_back({nums1[idx1][0], nums1[idx1][1]});
                idx1++;
            }
            else
            {
                // nums2 got smaller id
                ans.push_back({nums2[idx2][0], nums2[idx2][1]});
                idx2++;
            }
        }

        while (idx1 < len1)
        {
            ans.push_back({nums1[idx1][0], nums1[idx1][1]});
            idx1++;
        }
        while (idx2 < len2)
        {
            ans.push_back({nums2[idx2][0], nums2[idx2][1]});
            idx2++;
        }

        return ans;
    }
};
