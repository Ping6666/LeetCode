#include <string>
#include <vector>
using std::string, std::vector;

// Runtime: 11 ms (Beats 96.69 %), Memory: 85.46 MB (Beats 19.63 %).

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        // --- 1
        // TLE
        // int n = spaces.size();
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     s.insert(s.begin() + spaces[i], 1, ' ');
        // }
        // return s;
        // --- 1

        // --- 2
        int n = s.size(), n2 = spaces.size();
        string ans = "";

        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (idx < n2 && spaces[idx] == i)
            {
                ans += ' ';
                idx++;
            }
            ans += s[i];
        }
        return ans;
        // --- 2
    }
};
