#include <stdio.h>

#include <vector>

using namespace std;

class Solution
{
    // Runtime: 156 ms (Beats 93.66 %), Memory: 46.7 MB (Beats 96.99 %).

private:
    bool dfs(int i, vector<vector<int>> &graph, vector<char> &safe)
    {
        if (safe[i] != '0')
        {
            /* checked & checking */

            return safe[i] == '1';
        }

        /* checking */

        // not safe
        safe[i] = '2';

        for (int j = 0; j < graph[i].size(); j++)
        {
            if (!dfs(graph[i][j], graph, safe))
            {
                return false;
            }
        }

        // safe
        safe[i] = '1';

        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<char> safe(n, '0');
        // '0': default (unchecked)
        // '1': true
        // '2': false

        vector<int> safeNodes;

        for (int i = 0; i < n; i++)
        {
            if (dfs(i, graph, safe))
            {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};

void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int main()
{
    vector<vector<int>> graph;
    vector<int> safeNodes;
    Solution s;

    graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

    s = Solution();
    safeNodes = s.eventualSafeNodes(graph);
    printVector(safeNodes);

    graph = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};

    s = Solution();
    safeNodes = s.eventualSafeNodes(graph);
    printVector(safeNodes);

    return 0;
}
