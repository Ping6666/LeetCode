#include <vector>
#include <unordered_set>
#include <algorithm>
using std::vector, std::unordered_set, std::sort;

class Solution
{
    // Runtime: 2 ms (Beats 84.02 %), Memory: 12.36 MB (Beats 95.28 %).

public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i1 = 0, i2 = 0;
        int l1 = nums1.size(), l2 = nums2.size();

        vector<int> ans;
        int last_n;

        while (i1 < l1 && i2 < l2)
        {
            if (nums1[i1] == nums2[i2])
            {
                if (ans.size() == 0)
                {
                    // just insert
                    last_n = nums1[i1];
                    ans.push_back(last_n);
                }
                else if (last_n != nums1[i1])
                {
                    // make sure it is unique
                    last_n = nums1[i1];
                    ans.push_back(last_n);
                }
                i1++;
                i2++;
            }
            else if (nums1[i1] < nums2[i2])
            {
                i1++;
            }
            else if (nums1[i1] > nums2[i2])
            {
                i2++;
            }
        }

        return ans;
    }
};

/*
class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 14.11 MB (Beats 7.65 %).

public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1, set2;

        set1.insert(nums1.begin(), nums1.end());
        set2.insert(nums2.begin(), nums2.end());

        // TODO do swap on set1 & set2 to reduce the time complexity

        vector<int> ans;

        for (auto n : set1)
        {
            if (set2.find(n) != set2.end())
            {
                // if found
                ans.push_back(n);
            }
        }

        return ans;
    }
};
*/
