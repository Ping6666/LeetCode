#include <limits.h>
#include <string>
#include <vector>
#include <queue>
using std::string, std::vector, std::pair, std::priority_queue, std::greater;

// Runtime: 143 ms (Beats 92.93 %), Memory: 96.84 MB (Beats 76.46 %).

class Solution
{
private:
    void dijkstra(int n, const int (*edges)[26], int *matrix, int i)
    {
        // smallest at top
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, i);

        while (!pq.empty())
        {
            auto [dist, ch_from] = pq.top();
            pq.pop();

            if (matrix[ch_from] < dist)
            {
                continue;
            }

            for (int ch_to = 0; ch_to < 26; ch_to++)
            {
                if (edges[ch_from][ch_to] != INT_MAX)
                {
                    if (matrix[ch_to] > dist + edges[ch_from][ch_to])
                    {
                        matrix[ch_to] = dist + edges[ch_from][ch_to];
                        pq.emplace(matrix[ch_to], ch_to);
                    }
                }
            }
        }
    }

public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        // char from -> vector of char to
        int edges[26][26];
        int matrix[26][26];

        int edge_num = original.size();

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                edges[i][j] = INT_MAX;

                if (i == j)
                {
                    matrix[i][j] = 0;
                }
                else
                {
                    matrix[i][j] = INT_MAX;
                }
            }
        }

        for (int i = 0; i < edge_num; i++)
        {
            if (edges[original[i] - 'a'][changed[i] - 'a'] > cost[i])
            {
                edges[original[i] - 'a'][changed[i] - 'a'] = cost[i];
            }
        }

        for (int i = 0; i < 26; i++)
        {
            dijkstra(26, edges, matrix[i], i);
        }

        int n = source.size(), c;
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (source[i] != target[i])
            {
                c = matrix[source[i] - 'a'][target[i] - 'a'];
                if (c != INT_MAX)
                {
                    ans += c;
                }
                else
                {
                    return -1;
                }
            }
        }

        return ans;
    }
};
