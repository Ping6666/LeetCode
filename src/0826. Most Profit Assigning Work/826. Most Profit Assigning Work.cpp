#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using std::vector, std::priority_queue, std::sort, std::max;

// Runtime: 71 ms (Beats 32.60 %), Memory: 41.31 MB (Beats 39.43 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

struct DifficultyProfits
{
    int difficulty;
    int profit;

    DifficultyProfits(int d, int p) : difficulty(d), profit(p) {}
    bool operator<(const DifficultyProfits &rhs) const
    {
        // easy go first
        return difficulty > rhs.difficulty;
    }
};

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int n = difficulty.size();
        priority_queue<DifficultyProfits> dp_p_queue;
        for (int i = 0; i < n; i++)
        {
            dp_p_queue.push(DifficultyProfits(difficulty[i], profit[i]));
        }

        sort(worker.begin(), worker.end());

        int i = 0, l = worker.size();
        int ans = 0, curr_max = 0;
        while (i < l)
        {
            if (!dp_p_queue.empty() && dp_p_queue.top().difficulty <= worker[i])
            {
                curr_max = max(curr_max, dp_p_queue.top().profit);
                dp_p_queue.pop();
            }
            else
            {
                ans += curr_max;
                printf("%d %d %d\n", i, worker[i], curr_max);
                i++;
            }
        }

        return ans;
    }
};
