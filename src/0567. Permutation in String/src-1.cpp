#include <string>
#include <unordered_set>
using std::string, std::unordered_set;

// Runtime: 1960 ms (Beats 5.06 %), Memory: 455.72 MB (Beats 5.01 %).

string getEmbedding(int *arr)
{
    string s = "";

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }

        s += string('a' + i, arr[i]);
    }

    return s;
}

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int tgt[26] = {0};

        for (int i = 0; i < s1.size(); i++)
        {
            tgt[s1[i] - 'a']++;
        }

        int arr[26] = {0};

        // remainer
        int tmp[26];

        unordered_set<string> table;
        table.insert("");

        for (int i = 0; i < s2.size(); i++)
        {
            arr[s2[i] - 'a']++;
            table.insert(getEmbedding(arr));

            for (int j = 0; j < 26; j++)
            {
                // tmp[j] = tgt[j] - arr[j];
                tmp[j] = arr[j] - tgt[j];
            }

            if (table.find(getEmbedding(tmp)) != table.end())
            {
                return true;
            }
        }

        return false;
    }
};
