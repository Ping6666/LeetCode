#include <string>

using std::string, std::min;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int b = 0, a = 0, l = 0, o = 0, n = 0;

        for (int i = 0; i < text.size(); i++)
        {
            char t = text[i];
            if (t == 'b')
                b++;
            else if (t == 'a')
                a++;
            else if (t == 'l')
                l++;
            else if (t == 'o')
                o++;
            else if (t == 'n')
                n++;
        }

        l /= 2;
        o /= 2;
        return min(b, min(a, min(l, min(o, n))));
    }
};
