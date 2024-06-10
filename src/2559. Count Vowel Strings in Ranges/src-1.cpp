#include <vector>
#include <string>
#include <map>
#include <iostream>
using std::vector, std::string, std::map, std::pair;

// Runtime: 156 ms (Beats 5.41 %), Memory: 88.74 MB (Beats 5.41 %).

// magic 1
static auto _sync = std::ios_base::sync_with_stdio(0);
static auto _cin = std::cin.tie(0);
static auto _cout = std::cout.tie(0);

struct vecKeyComp
{
    bool operator()(pair<int, int> lhs, pair<int, int> rhs) const
    {
        if (lhs.second != rhs.second)
        {
            return lhs.second < rhs.second;
        }
        return lhs.first < rhs.first;
    }
};

class Solution
{
public:
    bool vowelCheck(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }

        return false;
    }

    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int l = words.size();
        vector<bool> vowel_table(l, false);

        for (int i = 0; i < l; i++)
        {
            if (vowelCheck(words[i].front()) && vowelCheck(words[i].back()))
            {
                vowel_table[i] = true;
            }
        }

        int ll = queries.size();
        map<pair<int, int>, vector<int>, vecKeyComp> words_range_query_indices_map;
        for (int i = 0; i < ll; i++)
        {
            words_range_query_indices_map[pair<int, int>(queries[i][0], queries[i][1])].push_back(i);
        }

        vector<int> ans(ll, 0);

        int holding = 0;
        vector<int> ans_table;

        int curr_idx, curr_ans;

        for (auto _item : words_range_query_indices_map)
        {
            curr_idx = _item.first.second;
            while (ans_table.size() < curr_idx + 1)
            {
                if (vowel_table[ans_table.size()])
                {
                    // +1
                    holding++;
                    ans_table.push_back(1 - holding);
                }
                else
                {
                    // +0
                    ans_table.push_back(0 - holding);
                }
            }

            curr_ans = ans_table[_item.first.first] + holding;

            for (auto idx : _item.second)
            {
                ans[idx] = curr_ans;
            }
        }

        /*
        Time Limit Exceed (TLE)
        for (int i = 0; i < ll; i++)
        {
            for (int j = queries[i][0]; j <= queries[i][1]; j++)
            {
                if (vowel_table[j])
                {
                    ans[i]++;
                }
            }
        }
        */

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
