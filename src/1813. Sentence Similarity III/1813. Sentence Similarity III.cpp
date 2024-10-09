#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.67 MB (Beats 98.16 %).

class Solution
{
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        int l1 = sentence1.size(), l2 = sentence2.size();

        int l = 0, r = 0;
        for (int i = 0; i < l1 && i < l2; i++)
        {
            if (sentence1[i] != sentence2[i])
            {
                break;
            }
            else
            {
                l = 0;
                if (sentence1[i] == ' ' ||
                    ((i == l1 - 1) && (i == l2 - 1)) ||
                    ((i == l1 - 1) && sentence2[i + 1] == ' ') ||
                    ((i == l2 - 1) && sentence1[i + 1] == ' '))
                {
                    l = i + 1;
                }
            }
        }

        for (int i = 0; i < l1 && i < l2; i++)
        {
            if (sentence1[l1 - i - 1] != sentence2[l2 - i - 1])
            {
                break;
            }
            else
            {
                r = 0;
                if (sentence1[l1 - i - 1] == ' ' ||
                    ((i == l1 - 1) && (i == l2 - 1)) ||
                    ((i == l1 - 1) && sentence2[l2 - i - 2] == ' ') ||
                    ((i == l2 - 1) && sentence1[l1 - i - 2] == ' '))
                {
                    r = i + 1;
                }
            }
        }

        printf("%d %d %d %d\n", l1, l2, l, r);

        return ((l + r) >= l1) || ((l + r) >= l2);
    }
};
