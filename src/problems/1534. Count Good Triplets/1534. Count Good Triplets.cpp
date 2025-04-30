#include <vector>
#include <cmath>
using std::vector, std::abs;

// Runtime: 3 ms (Beats 97.36 %), Memory: 10.91 MB (Beats 71.62 %).

class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        const int n = arr.size();

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (abs(arr[i] - arr[j]) > a)
                {
                    continue;
                }

                for (int k = j + 1; k < n; k++)
                {
                    if (abs(arr[j] - arr[k]) > b)
                    {
                        continue;
                    }
                    if (abs(arr[i] - arr[k]) > c)
                    {
                        continue;
                    }

                    ans++;
                }
            }
        }
        return ans;
    }
};
