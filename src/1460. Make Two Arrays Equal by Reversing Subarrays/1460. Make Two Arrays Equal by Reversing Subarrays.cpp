#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 3 ms (Beats 98.33 %), Memory: 17.34 MB (Beats 62.74 %).

class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        // method 01
        int n = target.size();

        for (int i = 0; i < n; i++)
        {
            if (target[i] != arr[i])
            {
                return false;
            }
        }

        return true;

        // // method 02
        // return target == arr;
    }
};
