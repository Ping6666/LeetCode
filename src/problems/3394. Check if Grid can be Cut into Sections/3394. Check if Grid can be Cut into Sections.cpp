#include <vector>
#include <algorithm>
using std::vector, std::sort, std::pair, std::max;

// Runtime: 52 ms (Beats 98.91 %), Memory: 201.30 MB (Beats 80.96 %).

class Solution
{
private:
    bool check(const int n, vector<vector<int>> &rectangles,
               const int s_idx, const int e_idx)
    {
        vector<pair<int, int>> edges;
        for (const auto &rect : rectangles)
        {
            edges.push_back({rect[s_idx], rect[e_idx]});
        }

        sort(edges.begin(), edges.end());

        // for (const auto &e : edges)
        // {
        //     printf("%d %d\n", e.first, e.second);
        // }
        // printf("\n");

        int count = 0;
        int prev = 0;
        for (const auto &e : edges)
        {
            if (prev != 0 && prev <= e.first)
            {
                count++;
                if (count >= 2)
                {
                    return true;
                }
            }
            prev = max(prev, e.second);
        }

        if (count >= 2)
        {
            return true;
        }

        return false;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        return check(n, rectangles, 0, 2) || check(n, rectangles, 1, 3);
    }
};
