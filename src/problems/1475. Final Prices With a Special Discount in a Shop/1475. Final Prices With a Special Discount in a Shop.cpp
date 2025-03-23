#include <vector>
#include <queue>
using std::vector, std::priority_queue, std::pair;

// Runtime: 0 ms (Beats 100.00 %), Memory: 13.97 MB (Beats 28.27 %).

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (prices[j] <= prices[i])
                {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }

        return prices;
    }
};

/*

// Runtime: 0 ms (Beats 100.00 %), Memory: 14.04 MB (Beats 24.39 %).

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        priority_queue<pair<int, int>> pq;

        int n = prices.size(), c;
        for (int i = 0; i < n; i++)
        {
            c = prices[i];

            while (!pq.empty())
            {
                auto t = pq.top();

                if (t.first < c)
                {
                    break;
                }

                pq.pop();

                prices[t.second] -= c;
            }

            pq.push({c, i});
        }

        return prices;
    }
};
*/
