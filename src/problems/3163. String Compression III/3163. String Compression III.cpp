#include <string>
using std::string, std::to_string;

// Runtime: 32 ms (Beats 64.10 %), Memory: 29.79 MB (Beats 57.63 %).

class Solution
{
private:
    int getMax(string &s, int idx)
    {
        int n = s.size();
        if (idx == -1)
        {
            return 1;
        }

        char c = s[idx];
        for (int i = 1; i < 9; i++)
        {
            if (s[idx + i] != c)
            {
                return i;
            }
        }

        return 9;
    }

public:
    string compressedString(string word)
    {
        int idx = 0, tmp;
        int n = word.size();

        string s = "";
        while (idx < n)
        {
            tmp = getMax(word, idx);
            s += to_string(tmp) + word[idx];
            idx += tmp;
        }

        return s;
    }
};
