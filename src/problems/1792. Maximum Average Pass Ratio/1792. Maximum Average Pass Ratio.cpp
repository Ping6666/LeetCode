#include <vector>
#include <queue>
using std::vector, std::priority_queue, std::pair;

// Runtime: 291 ms (Beats 89.74 %), Memory: 97.61 MB (Beats 71.43 %).

class Solution
{
private:
    double can_get(int p, int t)
    {
        // double r = (((double)(p + 1) / (double)(t + 1)) - ((double)p / (double)t));
        // printf("%d %d %f\n", p, t, r);

        return (((double)(p + 1) / (double)(t + 1)) - ((double)p / (double)t));
    }

public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        int n = classes.size();

        priority_queue<pair<double, pair<int, int>>> pq;
        for (const auto &c : classes)
        {
            pq.push({can_get(c[0], c[1]), {c[0], c[1]}});
        }

        for (int i = 0; i < extraStudents; i++)
        {
            auto t = pq.top();
            pq.pop();

            int pass = t.second.first + 1;
            int total = t.second.second + 1;

            // printf("%d %d\n", pass, total);

            pq.push({can_get(pass, total), {pass, total}});
        }

        double sum = 0;
        while (!pq.empty())
        {
            auto t = pq.top();
            pq.pop();

            sum += ((double)t.second.first / (double)t.second.second);
        }

        return sum / n;
    }
};
