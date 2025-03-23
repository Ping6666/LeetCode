#include <vector>
using std::vector;

// Runtime: 148 ms (Beats 91.94 %), Memory: 130.33 MB (Beats 94.80 %).

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    int dir[4] = {1, 1, -1, -1};

public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int y = 0, x = 0, curr_round = 0, curr_dir = 0;

        // printf("%d %d %d\n", 0, 0, head->val);
        ans[0][0] = head->val;
        head = head->next;

        bool valid;
        while (!(!head))
        {
            // printf("HI %d %d %d %d\n", curr_dir, x, y, curr_round);
            valid = false;
            if (curr_dir == 0 || curr_dir == 2)
            {
                // x
                if (((x + dir[curr_dir]) < (n - curr_round)) &&
                    ((x + dir[curr_dir]) >= curr_round))
                {
                    // valid
                    x += dir[curr_dir];
                    valid = true;
                }
            }
            else
            {
                // y
                if (((y + dir[curr_dir]) < (m - curr_round)) &&
                    ((y + dir[curr_dir]) >= curr_round))
                {
                    // valid
                    y += dir[curr_dir];
                    valid = true;
                }
            }

            if (valid)
            {
                // printf("%d %d %d\n", y, x, head->val);
                ans[y][x] = head->val;
                head = head->next;
            }
            else
            {
                // do turn
                curr_dir = (curr_dir + 1) % 4;
                if (curr_dir == 3)
                {
                    curr_round++;
                }
            }
        }

        return ans;
    }
};
