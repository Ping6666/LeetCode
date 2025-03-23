#include <vector>
#include <string>
using std::vector, std::string, std::min;

class Solution
{
    // Runtime: 3 ms (Beats 96.29 %), Memory: 10.88 MB (Beats 97.68 %).

public:
    vector<string> get_ans(vector<int> &table)
    {
        vector<string> ans;

        char c = 'a';
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < table[i]; j++)
            {
                ans.push_back(string(1, c));
            }
            c++;
        }

        return ans;
    }

    vector<string> commonChars(vector<string> &words)
    {
        vector<int> table(26, 0);
        vector<int> tmp_table(26, 0);

        int l = words.size();

        for (auto c : words[0])
        {
            table[c - 'a']++;
        }

        for (int i = 1; i < l; i++)
        {
            // add to tmp table
            for (auto c : words[i])
            {
                tmp_table[c - 'a']++;
            }

            // merge into table & clear tmp table
            for (int j = 0; j < 26; j++)
            {
                table[j] = min(table[j], tmp_table[j]);
                tmp_table[j] = 0;
            }
        }

        return get_ans(table);
    }
};
