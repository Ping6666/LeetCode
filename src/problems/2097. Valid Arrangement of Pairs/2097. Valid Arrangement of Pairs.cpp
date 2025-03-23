#include <vector>
#include <stack>
#include <unordered_map>
using std::vector, std::stack, std::unordered_map;

// Runtime: 303 ms (Beats 88.57 %), Memory: 264.46 MB (Beats 81.02 %).

class Solution
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> out_degree, in_degree;

        for (const auto &p : pairs)
        {
            adj[p[0]].push_back(p[1]);

            out_degree[p[0]]++;
            in_degree[p[1]]++;
        }

        // important part - start
        // ref. LeetCode Editorial - Approach 2: Hierholzer's Algorithm (Iterative)
        int s = -1;
        for (const auto &o : out_degree)
        {
            if (o.second == in_degree[o.first] + 1)
            {
                s = o.first;
                break;
            }
        }

        if (s == -1)
        {
            s = pairs[0][0];
        }
        // important part - end

        stack<int> table;
        table.push(s);

        vector<int> ans = {s};

        // Hierholzer’s algorithm
        while (!table.empty())
        {
            int t = table.top();

            if (!adj[t].empty())
            {
                int b = adj[t].back();
                adj[t].pop_back();

                table.push(b);
            }
            else
            {
                ans.push_back(t);

                table.pop();
            }
        }

        // for (int i = 0; i < ans.size(); i++)
        // {
        //     printf("%d ", ans[i]);
        // }
        // printf("\n");

        vector<vector<int>> result;
        for (int i = ans.size() - 1; i > 1; i--)
        {
            result.push_back({ans[i], ans[i - 1]});
        }

        return result;
    }
};
