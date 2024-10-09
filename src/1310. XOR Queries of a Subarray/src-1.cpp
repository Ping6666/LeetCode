#include <vector>
#include <algorithm>
using std::vector, std::sort;

// Runtime: 1859 ms (Beats 6.38 %), Memory: 42.65 MB (Beats 32.98 %).

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n_queries = queries.size();
        vector<int> queries_idx(n_queries, 0);
        for (int i = 0; i < n_queries; i++)
        {
            queries_idx[i] = i;
        }

        sort(queries_idx.begin(), queries_idx.end(), [&](int lhs, int rhs)
             { return (queries[lhs][1] != queries[rhs][1]) ? (queries[lhs][1] < queries[rhs][1]) : queries[lhs][0] < queries[rhs][0]; });

        // for (int i = 0; i < n_queries; i++)
        // {
        //     printf("%d %d %d\n", queries_idx[i], queries[queries_idx[i]][0], queries[queries_idx[i]][1]);
        // }

        int n_arr = arr.size();
        vector<int> xor_table(n_arr, 0);

        int done_idx = 0;
        vector<int> sorted_ans;

        for (int i = 0; i < n_arr; i++)
        {
            // curr num = arr[i]
            for (int j = 0; j < i + 1; j++)
            {
                xor_table[j] ^= arr[i];
                // printf("%d ", xor_table[j]);
            }
            // printf("\n");

            // printf("%d %d ", i, done_idx);
            // printf("%d\n", queries_idx[done_idx]);
            while (done_idx < n_queries && i == queries[queries_idx[done_idx]][1])
            {
                sorted_ans.push_back(xor_table[queries[queries_idx[done_idx]][0]]);
                done_idx++;
            }
        }

        vector<int> ans(n_queries, 0);
        for (int i = 0; i < n_queries; i++)
        {
            ans[queries_idx[i]] = sorted_ans[i];
        }
        return ans;
    }
};
