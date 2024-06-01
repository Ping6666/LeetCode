#include <stdio.h>

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    // Runtime: 15 ms (Beats 98.49 %), Memory: 13.3 MB (Beats 88.75 %).

private:
    bool dfs(int i, vector<vector<int>> &graph, vector<char> &can)
    {
        if (can[i] != '0')
        {
            return can[i] == '1';
        }

        can[i] = '2';

        for (int j = 0; j < graph[i].size(); j++)
        {
            if (!dfs(graph[i][j], graph, can))
            {
                return false;
            }
        }

        can[i] = '1';
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> path(numCourses);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            path[a].push_back(b);
        }

        for (int i = 0; i < numCourses; i++)
        {
            sort(path[i].begin(), path[i].end());
        }

        vector<char> can(numCourses, '0');
        // '0': default (unchecked)
        // '1': true
        // '2': false

        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(i, path, can))
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    int courses;
    vector<vector<int>> graph;

    bool can;
    Solution s;

    courses = 2;
    graph = {{1, 0}};

    s = Solution();
    can = s.canFinish(courses, graph);
    printf("%d\n", can);

    courses = 2;
    graph = {{1, 0}, {0, 1}};

    s = Solution();
    can = s.canFinish(courses, graph);
    printf("%d\n", can);

    courses = 3;
    graph = {{1, 0}, {0, 2}, {0, 1}};

    s = Solution();
    can = s.canFinish(courses, graph);
    printf("%d\n", can);

    return 0;
}
