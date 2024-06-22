#include <vector>
#include <iostream>
using std::vector, std::max;

// Runtime: 62 ms (Beats 99.11 %), Memory: 68.86 MB (Beats 92.92 %).
// Binary Search

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int start = 0, end = 1e9, mid;
        int ans = -1;

        int n = bloomDay.size();

        int continuous, bouquets;

        while (start <= end)
        {
            // count
            mid = (start + end) / 2;
            continuous = 0, bouquets = 0;
            for (int i = 0; i < n; i++)
            {
                if (bloomDay[i] <= mid)
                {
                    continuous++;

                    if (continuous >= k)
                    {
                        bouquets++;
                        continuous = 0;
                    }
                }
                else
                {
                    continuous = 0;
                }
            }

            // binary search
            if (bouquets >= m)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};

/*
class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if (m * k > n)
        {
            return -1;
        }

        int _max;
        vector<int> bucket;
        for (int i = k - 1; i < n; i++)
        {
            _max = bloomDay[i];
            for (int j = 1; j < k; j++)
            {
                _max = max(_max, bloomDay[i - j]);
            }
            bucket.push_back(_max);
        }

        return -1;
    }
};
*/
