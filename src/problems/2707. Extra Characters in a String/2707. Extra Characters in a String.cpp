#include <vector>
#include <set>
#include <string>
using std::vector, std::set, std::string, std::min;

class Solution
{
    // Runtime: 72 ms (Beats 85.95 %), Memory: 67.27 MB (Beats 85.13 %).
    // Dynamic Programming
    // Time Complexity: O(N2*log(N2) + N2*log(K) + N1*K*log(N2)), Space Complexity: O(N1+K+N2)

public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        // ref. https://stackoverflow.com/a/20052728
        set<string> word_set(dictionary.begin(), dictionary.end());
        set<int> len_set;

        for (auto word : dictionary)
        {
            len_set.insert(word.size());
        }

        int l = s.size();
        vector<int> _extra(l + 1, 0);

        int j = -1;
        for (int i = 1; i <= l; i++)
        {
            _extra[i] = _extra[i - 1] + 1;
            for (auto _len : len_set)
            {
                j = i - _len;
                if (j >= 0)
                {
                    string ss = s.substr(j, _len);
                    // printf("%d %d %d %s\n", i, j, _len, ss.c_str());

                    // ref. https://stackoverflow.com/a/1701083
                    // const bool _in = word_set.contains(ss);
                    const bool _in = word_set.find(ss) != word_set.end();
                    if (_in)
                    {
                        _extra[i] = min(_extra[i], _extra[j]);
                    }
                }
            }
        }

        // for (auto e : _extra)
        // {
        //     printf("%d ", e);
        // }
        // printf("\n");

        return _extra[l];
    }
};

int main()
{
    string s;
    vector<string> dictionary;

    s = "leetscode";
    dictionary = {"leet", "code", "leetcode"};
    Solution().minExtraChar(s, dictionary);

    return 0;
}
