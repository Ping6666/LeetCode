#include <string>

using std::string;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int word1_len = word1.length();
        int word2_len = word2.length();

        string s = "";
        for (int i = 0; i < std::min(word1_len, word2_len); i++)
        {
            s += word1[i];
            s += word2[i];
            // printf("%s\n", s.c_str());
        }

        if (word1_len < word2_len)
        {
            s += word2.substr(word1_len, word2_len - word1_len);
        }
        else if (word1_len > word2_len)
        {
            s += word1.substr(word2_len, word1_len - word2_len);
        }

        return s;
    }
};
