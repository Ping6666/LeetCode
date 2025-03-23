#include <vector>
#include <queue>
using std::vector, std::queue, std::pair;

// Runtime: 394 ms (Beats 91.56 %), Memory: 185.31 MB (Beats 83.62 %).

// NOTE
// if do `pq.emplace(c, j)` for all case will cause LTE
// if do `pq.emplace(c, j)` on first time and sec. time can pass,
//   since we only care about sec. min. therefore, only do bfs for first and sec. time.

class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> edges_table(n + 1);
        for (const auto &e : edges)
        {
            edges_table[e[0]].push_back(e[1]);
            edges_table[e[1]].push_back(e[0]);
        }

        // pair<int, int>: edge count, curr node idx
        queue<pair<int, int>> pq;
        pq.emplace(0, 1);

        int two_change = 2 * change;

        // edge count
        vector<int> dist_min(n + 1, -1), dist_2_min(n + 1, -1);

        while (!pq.empty())
        {
            auto [c, i] = pq.front();
            pq.pop();

            c++;

            for (const auto &j : edges_table[i])
            {
                // // SEE NOTE
                // pq.emplace(c, j);

                if (dist_min[j] == -1)
                {
                    dist_min[j] = c;

                    // SEE NOTE
                    pq.emplace(c, j);
                }
                else if (dist_2_min[j] == -1 && c > dist_min[j])
                {
                    // strictly larger
                    dist_2_min[j] = c;

                    if (j == n)
                    {
                        // strictly larger
                        int acc_time = 0;

                        while (c > 0)
                        {
                            if ((acc_time % two_change) >= change)
                            {
                                // wait red
                                acc_time += two_change - (acc_time % two_change);
                            }
                            acc_time += time;
                            c--;
                        }

                        return acc_time;
                    }

                    // SEE NOTE
                    pq.emplace(c, j);
                }
            }
        }

        // should not come here
        return -1;
    }
};
