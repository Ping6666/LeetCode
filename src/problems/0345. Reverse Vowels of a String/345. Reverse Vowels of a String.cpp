#include <string>
#include <vector>
using std::string, std::vector;

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 9.00 MB (Beats 95.36 %).
    // use two idx to find who to swap

public:
    bool checker(char c)
    {
        if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ||
            (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'))
        {
            return true;
        }
        return false;
    }

    string reverseVowels(string s)
    {
        int l = s.size();
        int i = 0, j = l - 1;

        char c;

        while (i < j)
        {
            if (checker(s[i]) && checker(s[j]))
            {
                // do swap
                c = s[i];
                s[i] = s[j];
                s[j] = c;

                i++;
                j--;
            }
            else
            {
                if (!checker(s[i]))
                {
                    // not hit i
                    i++;
                }

                if (!checker(s[j]))
                {
                    // not hit j
                    j--;
                }
            }
        }

        return s;
    }
};

/*
class Solution
{
    // Runtime: 3 ms (Beats 95.74 %), Memory: 9.79 MB (Beats 26.54 %).
    // use vector to store the idx

public:
    string reverseVowels(string s)
    {
        vector<int> vowels_idx;

        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') ||
                (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'))
            {
                vowels_idx.push_back(i);
            }
        }

        int l = vowels_idx.size();
        char c;
        for (int i = 0; i < (l / 2); i++)
        {
            c = s[vowels_idx[i]];
            s[vowels_idx[i]] = s[vowels_idx[l - i - 1]];
            s[vowels_idx[l - i - 1]] = c;
        }

        return s;
    }
};
*/
