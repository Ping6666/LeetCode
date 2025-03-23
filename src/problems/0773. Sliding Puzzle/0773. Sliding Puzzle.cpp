#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using std::vector, std::queue, std::string, std::to_string, std::unordered_set;

// Runtime: 0 ms (Beats 100.00 %), Memory: 10.86 MB (Beats 95.33 %).

class Solution
{
public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        vector<vector<int>> dir = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4},
        };

        string target = "123450";
        string _curr = "";

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                _curr += to_string(board[i][j]);
            }
        }

        unordered_set<string> visited;
        queue<string> q;

        q.push(_curr);
        visited.insert(_curr);

        int moves = 0;
        while (!q.empty())
        {
            int same_move_count = q.size();
            while (same_move_count-- > 0)
            {
                string _next = q.front();
                q.pop();

                if (_next == target)
                {
                    return moves;
                }

                int zero_idx = _next.find('0');

                for (int idx : dir[zero_idx])
                {
                    string _new = _next;
                    std::swap(_new[zero_idx], _new[idx]);

                    if (visited.count(_new))
                    {
                        continue;
                    }

                    q.push(_new);
                    visited.insert(_new);
                }
            }
            moves++;
        }

        return -1;
    }
};
