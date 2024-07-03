#include <vector>
using std::vector;

class Solution
{
    // Runtime: 82 ms (Beats 98.24 %), Memory: 63.11 MB (Beats 91.22 %).
private:
    void dfs(int from, int mid, vector<vector<int>> &uni_edges, vector<vector<int>> &ans)
    {
        int to;
        for (int j = 0; j < uni_edges[mid].size(); j++)
        {
            to = uni_edges[mid][j];
            if (ans[to].size() == 0 || ans[to].back() != from)
            {
                ans[to].push_back(from);
                dfs(from, to, uni_edges, ans);
            }
        }

        return;
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> uni_edges(n);

        for (int i = 0; i < edges.size(); i++)
        {
            uni_edges[edges[i][0]].push_back(edges[i][1]);
        }

        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++)
        {
            dfs(i, i, uni_edges, ans);
        }

        return ans;
    }
};

/*
class Solution
{
    // Runtime: 162 ms (Beats 48.41 %), Memory: 65.93 MB (Beats 83.75 %).
private:
    void dfs(int from, vector<vector<int>> &uni_edges, vector<bool> &checked)
    {
        int to;
        for (int j = 0; j < uni_edges[from].size(); j++)
        {
            to = uni_edges[from][j];
            if (!checked[to])
            {
                checked[to] = true;
                dfs(to, uni_edges, checked);
            }
        }

        return;
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> uni_edges(n, vector<int>());

        for (int i = 0; i < edges.size(); i++)
        {
            uni_edges[edges[i][0]].push_back(edges[i][1]);
        }

        vector<vector<int>> ans(n, vector<int>());
        for (int i = 0; i < n; i++)
        {
            vector<bool> checked(n, false);
            dfs(i, uni_edges, checked);

            for (int j = 0; j < n; j++)
            {
                if (checked[j])
                {
                    ans[j].push_back(i);
                }
            }
        }

        return ans;
    }
};
*/
