#include <string>
#include <vector>
using std::string, std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 23.40 MB (Beats 90.68 %).

class Solution
{
private:
    bool isPrefixAndSuffix(string str1, string str2)
    {
        int len1 = str1.size();
        int len2 = str2.size();

        if (len1 > len2)
        {
            return false;
        }

        bool check = true;
        for (int i = 0; i < len1 && check; i++)
        {
            if (str1[i] != str2[i] || str1[len1 - i - 1] != str2[len2 - i - 1])
            {
                check = false;
                break;
            }
        }
        return check;
    }

public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isPrefixAndSuffix(words[i], words[j]))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
