#include <vector>
#include <queue>
#include <iostream>
using std::vector, std::priority_queue, std::pair, std::greater, std::less;

// without magic
//   Runtime: 230 ms (Beats 62.74 %), Memory: 107.95 MB (Beats 29.72 %).

// with magic
//   Runtime: 196 ms (Beats 98.58 %), Memory: 107.95 MB (Beats 29.72 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> g_pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> l_pq;

        for (int i = 0; i < arrays.size(); i++)
        {
            g_pq.emplace(arrays[i][0], i);
            l_pq.emplace(arrays[i][arrays[i].size() - 1], i);

            if (g_pq.size() > 2)
            {
                g_pq.pop();
            }
            if (l_pq.size() > 2)
            {
                l_pq.pop();
            }
        }

        pair<int, int> _max, _min;
        pair<int, int> _max_2, _min_2;

        _min_2 = g_pq.top();
        g_pq.pop();
        _min = g_pq.top();
        _max_2 = l_pq.top();
        l_pq.pop();
        _max = l_pq.top();

        if (_max.second != _min.second)
        {
            return _max.first - _min.first;
        }

        int a = _max_2.first - _min.first;
        int b = _max.first - _min_2.first;

        if (a > b)
        {
            return a;
        }
        return b;
    }
};
