#include <string>

using std::string;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        int str1_len = str1.length();
        int str2_len = str2.length();

        if (str1_len == 0 || str2_len == 0)
        {
            return "";
        }

        for (int i = 0; i < std::min(str1_len, str2_len); i++)
        {
            if (str1[i] != str2[i])
            {
                return "";
            }
        }

        if (str1_len > str2_len)
        {
            return gcdOfStrings(str1.substr(str2_len, str1_len - str2_len), str2);
        }
        else if (str1_len < str2_len)
        {
            return gcdOfStrings(str1, str2.substr(str1_len, str2_len - str1_len));
        }

        return str1;
    }
};
