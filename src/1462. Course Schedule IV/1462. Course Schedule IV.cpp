#include <vector>
#include <queue>
#include <unordered_set>
using std::vector, std::queue, std::unordered_set;

// constraints: no cycles!!!
// Runtime: 27 ms (Beats 76.61 %), Memory: 72.35 MB (Beats 50.24 %).

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> in_degree(numCourses, 0);
        for (const auto &p : prerequisites)
        {
            in_degree[p[1]]++;
            adj[p[0]].push_back(p[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<unordered_set<int>> table(numCourses);
        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            for (const auto &n : adj[f])
            {
                table[n].insert(f);
                for (const auto &p : table[f])
                {
                    table[n].insert(p);
                }

                if (--in_degree[n] == 0)
                {
                    q.push(n);
                }
            }
        }

        vector<bool> ans;
        for (const auto &q : queries)
        {
            ans.push_back(table[q[1]].count(q[0]) != 0);
        }
        return ans;
    }
};
