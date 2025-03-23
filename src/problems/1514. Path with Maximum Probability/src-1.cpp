#include <vector>
#include <queue>
using std::vector, std::priority_queue, std::pair, std::less;

// Memory Limit Exceeded

class Solution
{
private:
    void dijkstra(int n, vector<vector<double>> &adj, vector<double> &matrix, int src, int tgt)
    {
        priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>>> pq;
        pq.emplace(1.0, src);
        matrix[src] = 1;

        double curr_max = matrix[tgt];
        while (!pq.empty())
        {
            auto [p, j] = pq.top();
            pq.pop();

            if (matrix[j] > p)
            {
                continue;
            }

            if (matrix[tgt] < matrix[j] * adj[j][tgt])
            {
                curr_max = matrix[tgt] = matrix[j] * adj[j][tgt];
                pq.emplace(matrix[tgt], tgt);
            }

            for (int k = 0; k < n; k++)
            {
                if (k == tgt)
                {
                    continue;
                }

                if (matrix[k] < matrix[j] * adj[j][k])
                {
                    matrix[k] = matrix[j] * adj[j][k];
                    if (curr_max <= matrix[k])
                    {
                        pq.emplace(matrix[k], k);
                    }
                }
            }
        }

        return;
    }

public:
    double
    maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<vector<double>> adj(n, vector<double>(n, 0));
        vector<double> matrix(n, 0);

        int a, b;
        double p;
        for (int i = 0; i < edges.size(); i++)
        {
            a = edges[i][0], b = edges[i][1], p = succProb[i];
            adj[a][b] = p, adj[b][a] = p;
        }
        return 1;

        if (start_node == end_node)
        {
            return 1;
        }

        dijkstra(n, adj, matrix, start_node, end_node);

        return matrix[end_node];
    }
};
