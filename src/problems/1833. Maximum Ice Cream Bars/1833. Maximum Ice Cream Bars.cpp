#include <vector>

using std::vector;

// counting sort

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        const int n = costs.size();
        int _max = costs[0];
        for (int i = 0; i < n; i++)
        {
            _max = std::max(_max, costs[i]);
        }

        vector<int> counts = vector<int>(_max + 1);

        // count
        for (int i = 0; i < n; i++)
        {
            counts[costs[i]]++;
        }
        // do prefix sum on counts
        int _sum = 0;
        for (int i = 0; i <= _max; i++)
        {

            counts[i] += _sum;
            _sum = counts[i];
        }

        vector<int> sorted_costs = vector<int>(n);
        for (int i = n - 1, _idx, cost; i >= 0; i--)
        {
            cost = costs[i];
            _idx = --counts[cost];
            sorted_costs[_idx] = cost;
        }

        int i = 0, c = 0;
        while (coins >= 0 && i < n && coins >= sorted_costs[i])
        {
            coins -= sorted_costs[i];
            i++;
            c++;
        }
        return c;
    }
};
