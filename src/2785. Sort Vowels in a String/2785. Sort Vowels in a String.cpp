#include <string>
#include <vector>
#include <algorithm>
using std::string, std::vector, std::sort;

class Solution
{
    // Runtime: 22 ms (Beats 94.70 %), Memory: 13.56 MB (Beats 99.29 %).
    // in-place, table, change the content to store the idx

    // Runtime: 28 ms (Beats 78.99 %), Memory: 18.52 MB (Beats 20.05 %).
    // in-place, table, use vector store the idx

public:
    int checker(char c)
    {
        if (c == 'A')
        {
            return 0;
        }
        if (c == 'E')
        {
            return 1;
        }
        if (c == 'I')
        {
            return 2;
        }
        if (c == 'O')
        {
            return 3;
        }
        if (c == 'U')
        {
            return 4;
        }

        if (c == 'a')
        {
            return 5;
        }
        if (c == 'e')
        {
            return 6;
        }
        if (c == 'i')
        {
            return 7;
        }
        if (c == 'o')
        {
            return 8;
        }
        if (c == 'u')
        {
            return 9;
        }

        return -1;
    }

    char get_char(int i)
    {
        if (i == 0)
        {
            return 'A';
        }
        if (i == 1)
        {
            return 'E';
        }
        if (i == 2)
        {
            return 'I';
        }
        if (i == 3)
        {
            return 'O';
        }
        if (i == 4)
        {
            return 'U';
        }

        if (i == 5)
        {
            return 'a';
        }
        if (i == 6)
        {
            return 'e';
        }
        if (i == 7)
        {
            return 'i';
        }
        if (i == 8)
        {
            return 'o';
        }
        if (i == 9)
        {
            return 'u';
        }

        return '#';
    }

    string sortVowels(string s)
    {
        vector<int> vowels(10, 0);
        // vector<int> idx;

        int c_idx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            c_idx = checker(s[i]);
            if (c_idx != -1)
            {
                vowels[c_idx]++;
                // idx.push_back(i);
                s[i] = '#';
            }
        }

        c_idx = 0;
        char c = get_char(c_idx);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#')
            {
                if (vowels[c_idx] > 0)
                {
                    vowels[c_idx]--;
                    // s[idx[i]] = c;
                    s[i] = c;
                }
                else
                {
                    c_idx++;
                    c = get_char(c_idx);
                    i--;
                }
            }
        }

        return s;
    }
};

/*
class Solution
{
    // Runtime: 26 ms (Beats 85.86 %), Memory: 19.54 MB (Beats 16.01 %).
    // in-place, sort

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

    string sortVowels(string s)
    {
        // string vowels;
        vector<char> vowels;

        vector<int> idx;

        for (int i = 0; i < s.size(); i++)
        {
            if (checker(s[i]))
            {
                // vowels += s[i];
                vowels.push_back(s[i]);

                idx.push_back(i);
            }
        }

        sort(vowels.begin(), vowels.end());

        for (int i = 0; i < idx.size(); i++)
        {
            s[idx[i]] = vowels[i];
        }

        return s;
    }
};
*/
