#include <vector>
using std::vector;

// Runtime: 82 ms (Beats 99.69 %), Memory: 52.98 MB (Beats 99.33 %).

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<double> probs(n, 0);
        probs[start_node] = 1;

        int num_edges = edges.size();

        int a, b;
        double p;
        bool has_update;

        for (int i = 0; i < n; i++)
        {
            has_update = false;
            for (int j = 0; j < num_edges; j++)
            {
                a = edges[j][0], b = edges[j][1], p = succProb[j];
                if (probs[a] < probs[b] * p)
                {
                    probs[a] = probs[b] * p;
                    has_update = true;
                }
                if (probs[b] < probs[a] * p)
                {
                    probs[b] = probs[a] * p;
                    has_update = true;
                }
            }

            if (!has_update)
            {
                // early break (very important)
                break;
            }
        }

        return probs[end_node];
    }
};
