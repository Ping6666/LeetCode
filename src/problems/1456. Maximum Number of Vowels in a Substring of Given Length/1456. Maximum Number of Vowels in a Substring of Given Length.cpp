#include <string>

using std::string;

class Solution
{
private:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        return false;
    }

public:
    int maxVowels(string s, int k)
    {
        int c = 0, m;
        for (int i = 0; i < k; i++)
        {
            if (this->isVowel(s[i]))
            {
                c++;
            }
        }
        m = c;
        if (m == k)
            return k;
        for (int i = 0; i < s.size() - k; i++)
        {
            if (this->isVowel(s[i]))
            {
                c--;
            }
            if (this->isVowel(s[i + k]))
            {
                c++;
            }
            m = std::max(c, m);
            if (m == k)
                return k;
        }
        return m;
    }
};
