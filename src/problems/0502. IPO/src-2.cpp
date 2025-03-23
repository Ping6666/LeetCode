#include <vector>
#include <queue>
#include <iostream>
using std::vector, std::priority_queue;

// Runtime: 104 ms (Beats 97.97 %), Memory: 81.17 MB (Beats 92.55 %).

struct CapitalProfits
{
    int capital;
    int profit;

    CapitalProfits(int c, int p) : capital(c), profit(p) {}
    bool operator<(const CapitalProfits &rhs) const
    {
        return capital > rhs.capital;
    }
};

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        priority_queue<int> p_pqueue;
        priority_queue<CapitalProfits> cp_pqueue;

        for (int i = 0; i < profits.size(); i++)
        {
            if (capital[i] <= w)
            {
                p_pqueue.push(profits[i]);
            }
            else
            {
                cp_pqueue.push(CapitalProfits(capital[i], profits[i]));
            }
        }

        while (k > 0 && !p_pqueue.empty())
        {
            w += p_pqueue.top(), p_pqueue.pop();
            k--;

            while (!cp_pqueue.empty() && cp_pqueue.top().capital <= w)
            {
                p_pqueue.push(cp_pqueue.top().profit), cp_pqueue.pop();
            }
        }

        return w;
    }
};
