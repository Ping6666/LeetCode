#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <iostream>
using std::string, std::vector, std::set, std::unordered_set;

class Solution
{
    // Runtime: 51 ms (Beats 96.74 %), Memory: 42.49 MB (Beats 87.79 %).
    // in-place

public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        // magic
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);

        set<int> len_table;
        unordered_set<string> str_table;

        for (auto d : dictionary)
        {
            len_table.insert(d.size());
            str_table.insert(d);
        }

        int i = 0, j = 0, l = sentence.size();
        while (i < l)
        {
            while (j < l && sentence[j] != ' ')
            {
                j++;
            }

            for (auto ll : len_table)
            {
                if (str_table.find(sentence.substr(i, ll)) != str_table.end())
                {
                    // found
                    int d = j - i - ll;

                    if (d > 0)
                    {
                        sentence.erase(sentence.begin() + i + ll, sentence.begin() + j);

                        l -= d;
                        j -= d;
                    }

                    break;
                }
            }

            i = ++j;
        }

        return sentence;
    }
};

int main()
{
    vector<string> dictionary;
    string sentence;
    string ans;

    dictionary = {"cat", "bat", "rat"};
    sentence = "the cattle was rattled by the battery";
    ans = Solution().replaceWords(dictionary, sentence);
    printf("%c\n", ans.c_str());

    dictionary = {"a", "aa", "aaa", "aaaa"};
    sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
    ans = Solution().replaceWords(dictionary, sentence);
    printf("%c\n", ans.c_str());

    return 0;
}
