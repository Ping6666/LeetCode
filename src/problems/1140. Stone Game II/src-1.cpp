#include <vector>
using std::vector, std::max, std::pair;

// get TLE

class Solution
{
private:
    pair<int, int> stones(vector<int> &piles, int idx, int m, bool is_alice)
    {
        // return {Alice, Bob}

        int n = piles.size();
        if (idx >= n)
        {
            return {0, 0};
        }

        pair<int, int> c = {0, 0};
        for (int i = 1; i <= 2 * m; i++)
        {
            int stones_sum = 0;
            for (int ii = 0; ii < i && idx + ii < n; ii++)
            {
                stones_sum += piles[idx + ii];
            }

            pair<int, int> p = stones(piles, idx + i, max(m, i), !is_alice);

            if (is_alice)
            {
                if (c.first < p.first + stones_sum)
                {
                    c = p;
                    c.first += stones_sum;
                }
            }
            else
            {
                if (c.second < p.second + stones_sum)
                {
                    c = p;
                    c.second += stones_sum;
                }
            }

            if (idx + i >= n)
            {
                break;
            }
        }

        return c;
    }

public:
    int stoneGameII(vector<int> &piles)
    {
        return stones(piles, 0, 1, true).first;
    }
};
