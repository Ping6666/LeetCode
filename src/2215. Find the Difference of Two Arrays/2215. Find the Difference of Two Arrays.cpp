#include <vector>
#include <unordered_set>
#include <algorithm>
using std::vector, std::unordered_set, std::find;

class Solution
{
    // Runtime: 31 ms (Beats 87.85 %), Memory: 37.72 MB (Beats 25.02 %).
    // use unordered_set

    //   or there can also be
    //     sort (see ref: q.0349)
    //     vector with size 2000 (see question's constraint)
    //     bitset with size 2000 (see question's constraint)

public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1, set2;

        set1.insert(nums1.begin(), nums1.end());
        set2.insert(nums2.begin(), nums2.end());

        // TODO do swap on set1 & set2 to reduce the time complexity

        unordered_set<int> intersection;

        for (auto n : set1)
        {
            if (set2.find(n) != set2.end())
            {
                // if found
                intersection.insert(n);
            }
        }

        vector<vector<int>> ans;
        vector<int> ans1, ans2;

        for (auto n : set1)
        {
            if (intersection.find(n) == intersection.end())
            {
                // didnot get n in intersection
                ans1.push_back(n);
            }
        }

        for (auto n : set2)
        {
            if (intersection.find(n) == intersection.end())
            {
                // didnot get n in intersection
                ans2.push_back(n);
            }
        }

        ans.push_back(ans1);
        ans.push_back(ans2);

        return ans;
    }
};

/*
class Solution
{
    // Runtime: 79 ms (Beats 10.22 %), Memory: 29.12 MB (Beats 98.45 %).

public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> ans;
        vector<int> ans1, ans2;

        for (auto n : nums1)
        {
            if (find(nums2.begin(), nums2.end(), n) == nums2.end())
            {
                // didnot get n in nums2
                if (find(ans1.begin(), ans1.end(), n) == ans1.end())
                {
                    // didnot get n in ans1
                    ans1.push_back(n);
                }
            }
        }

        for (auto n : nums2)
        {
            if (find(nums1.begin(), nums1.end(), n) == nums1.end())
            {
                // didnot get n in nums1
                if (find(ans2.begin(), ans2.end(), n) == ans2.end())
                {
                    // didnot get n in ans2
                    ans2.push_back(n);
                }
            }
        }

        ans.push_back(ans1);
        ans.push_back(ans2);

        return ans;
    }
};
*/
