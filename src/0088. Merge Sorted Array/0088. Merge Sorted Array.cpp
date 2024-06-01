#include <vector>
using namespace std;

class Solution
{
    // Runtime: 0 ms (100.00 %), Memory: 9.0 MB (90.60 %).
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int iVec1 = 0;
        for (int iVec2 = 0; iVec2 < n; iVec2++)
        {
            if (iVec1 >= m)
            {
                nums1.insert(nums1.begin() + iVec1 + iVec2, nums2[iVec2]);
            }
            else if (iVec1 < m && iVec2 < n && nums1[iVec1 + iVec2] > nums2[iVec2])
            {
                nums1.insert(nums1.begin() + iVec1 + iVec2, nums2[iVec2]);
            }
            else
            {
                iVec2--;
                iVec1++;
            }
        }
        nums1.erase(nums1.begin() + m + n, nums1.end());
    }
};
