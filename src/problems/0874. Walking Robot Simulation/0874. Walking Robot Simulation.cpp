#include <vector>
#include <unordered_set>
using std::vector, std::unordered_set;

// Runtime: 53 ms (Beats 95.30 %), Memory: 36.28 MB (Beats 99.45 %).

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        const int magic = 60001;
        unordered_set<int> obs;
        for (const auto &o : obstacles)
        {
            obs.insert(o[0] + o[1] * magic);
        }

        const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int curr_dir = 0, curr_x = 0, curr_y = 0;

        int tmp, max_dist = 0;
        for (const auto &c : commands)
        {
            if (c == -1)
            {
                curr_dir = (curr_dir + 1) % 4;
            }
            else if (c == -2)
            {
                curr_dir = (curr_dir + 3) % 4;
            }
            else
            {
                for (int i = 0; i < c; i++)
                {
                    tmp = curr_x + dir[curr_dir][0] + magic * (curr_y + dir[curr_dir][1]);
                    if (obs.find(tmp) != obs.end())
                    {
                        break;
                    }
                    curr_x += dir[curr_dir][0];
                    curr_y += dir[curr_dir][1];
                }

                tmp = curr_x * curr_x + curr_y * curr_y;
                if (tmp > max_dist)
                {
                    max_dist = tmp;
                }
            }
        }

        return max_dist;
    }
};
