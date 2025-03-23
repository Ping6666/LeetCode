#include <vector>
#include <queue>
using std::vector, std::priority_queue, std::max;

// Runtime: 35 ms (Beats 55.37 %), Memory: 18.64 MB (Beats 50.00 %).

class Solution
{
private:
    vector<vector<int>> dirs = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    };

    class Cell
    {
    public:
        int height;
        int row;
        int col;

        Cell(int height, int row, int col) : height(height), row(row), col(col) {}

        bool operator<(const Cell &other) const
        {
            return height >= other.height;
        }
    };

public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int m = heightMap.size(), n = heightMap[0].size();

        priority_queue<Cell> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            pq.push(Cell(heightMap[i][0], i, 0));
            pq.push(Cell(heightMap[i][n - 1], i, n - 1));
            visited[i][0] = visited[i][n - 1] = true;
        }

        for (int i = 1; i < n - 1; i++)
        {
            pq.push(Cell(heightMap[0][i], 0, i));
            pq.push(Cell(heightMap[m - 1][i], m - 1, i));
            visited[0][i] = visited[m - 1][i] = true;
        }

        int ans = 0;
        while (!pq.empty())
        {
            auto t = pq.top();
            pq.pop();

            int h = t.height;
            int r = t.row;
            int c = t.col;

            for (int i = 0; i < 4; i++)
            {
                int rr = r + dirs[i][0];
                int cc = c + dirs[i][1];

                if (0 <= rr && rr < m && 0 <= cc && cc < n && !visited[rr][cc])
                {
                    int hh = heightMap[rr][cc];

                    if (hh < h)
                    {
                        ans += h - hh;
                    }

                    pq.push(Cell(max(h, hh), rr, cc));
                    visited[rr][cc] = true;
                }
            }
        }
        return ans;
    }
};
