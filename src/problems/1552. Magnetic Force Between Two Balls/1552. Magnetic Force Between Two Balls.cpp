#include <vector>
#include <algorithm>
#include <iostream>
using std::vector, std::sort;

// Runtime: 89 ms (Beats 98.08 %), Memory: 61.34 MB (Beats 73.97 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
public:
    bool checker(vector<int> &position, int mid, int m)
    {
        int curr_sum = 0;
        for (int i = 0; i < position.size(); i++)
        {
            curr_sum += position[i];
            if (curr_sum >= mid)
            {
                m--;

                if (m < 0)
                {
                    return true;
                }
                curr_sum = 0;
            }
        }

        return false;
    }

    int maxDistance(vector<int> &position, int m)
    {
        int n = position.size();
        sort(position.begin(), position.end());

        for (int i = n - 1; i >= 1; i--)
        {
            position[i] -= position[i - 1];
        }
        position.erase(position.begin());

        int start = 1, end = 1e9;
        int mid, ans;

        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (this->checker(position, mid, m - 2))
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return ans;
    }
};
