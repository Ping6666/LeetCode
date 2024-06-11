#include <vector>
#include <unordered_map>
#include <map>
using std::vector, std::unordered_map, std::map;

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 10.01 MB (Beats 54.14 %).
    // not in-place

    // It is not strictly constraints, so this may be done in in-place.

public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> do_appear;
        map<int, int> not_appear;

        for (auto n : arr2)
        {
            do_appear[n] = 0;
        }

        for (auto n : arr1)
        {
            if (do_appear.find(n) != do_appear.end())
            {
                // if is in do appear
                do_appear[n]++;
            }
            else
            {
                not_appear[n]++;
            }
        }

        vector<int> ans;
        for (auto n : arr2)
        {
            ans.insert(ans.end(), do_appear[n], n);
        }

        for (auto n : not_appear)
        {
            ans.insert(ans.end(), n.second, n.first);
        }

        return ans;
    }
};
