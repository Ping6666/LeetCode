#include <vector>
#include <string>
#include <iostream>
using std::vector, std::string;

// use idx loop through the queries
//   `for (int i = 0; i < q_len; i++`
//   Runtime: 78 ms (Beats 97.97 %), Memory: 66.94 MB (Beats 93.24 %).
// use auto type var loop through the queries
//   `for (auto q : queries)`
//   Runtime: 88 ms (Beats 93.58 %), Memory: 72.09 MB (Beats 23.65 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

class Solution
{
public:
    bool vowelCheck(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int l = words.size();

        // store the num of `true` from 0 to curr idx
        vector<int> vowel_table(l + 1, 0);

        for (int i = 0; i < l; i++)
        {
            if (vowelCheck(words[i].front()) && vowelCheck(words[i].back()))
            {
                vowel_table[i + 1] = vowel_table[i] + 1;
            }
            else
            {
                vowel_table[i + 1] = vowel_table[i];
            }
        }

        int q_len = queries.size();
        vector<int> ans(q_len, 0);
        for (int i = 0; i < q_len; i++)
        {
            // start: q[0]
            //   end: q[1] + 1 (+1 because inclusive)
            ans[i] = vowel_table[queries[i][1] + 1] - vowel_table[queries[i][0]];
        }

        return ans;
    }
};

int main()
{
    vector<string> words;
    vector<vector<int>> queries;

    words = {"aba", "bcb", "ece", "aa", "e"};
    queries = {{0, 2}, {1, 4}, {1, 1}};
    Solution().vowelStrings(words, queries);

    return 0;
}
