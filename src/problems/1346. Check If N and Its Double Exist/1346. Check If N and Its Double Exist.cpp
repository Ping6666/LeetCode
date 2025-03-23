#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 13.32 MB (Beats 35.64 %).

// Time: O(n^2); Space: O(1)
// or
// Time: O(n*log(n)); Space: (n*log(n))

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        // int n = arr.size();

        int i, j;
        for (i = 0; i < arr.size(); i++)
        {
            for (j = i + 1; j < arr.size(); j++)
            {
                if (arr[i] == arr[j] * 2 || arr[i] * 2 == arr[j])
                {
                    return true;
                }
            }
        }

        return false;
    }
};
