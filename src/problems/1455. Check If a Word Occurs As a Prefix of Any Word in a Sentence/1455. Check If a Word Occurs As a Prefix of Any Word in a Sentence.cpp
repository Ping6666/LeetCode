#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 8.38 MB (Beats 6.42 %).

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        sentence += " ";
        int n1 = sentence.size(), n2 = searchWord.size();

        int ii = 0, c = 0;
        bool check;

        for (int i = 0; i < n1; i++)
        {
            if (sentence[i] == ' ')
            {
                // string sub = sentence.substr(ii, i - ii);

                c++;
                if ((i - ii) >= n2)
                {
                    check = true;
                    for (int j = 0; j < n2; j++)
                    {
                        if (sentence[ii + j] != searchWord[j])
                        {
                            check = false;
                            break;
                        }
                    }

                    if (check)
                    {
                        return c;
                    }
                }

                ii = i + 1;
            }
        }

        return -1;
    }
};
