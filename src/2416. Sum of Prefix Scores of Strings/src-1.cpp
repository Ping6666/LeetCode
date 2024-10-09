#include <vector>
#include <string>
#include <unordered_map>
using std::vector, std::string, std::unordered_map;

// TLE

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        unordered_map<string, int> table;
        for (const auto &s : words)
        {
            for (int i = 1; i <= s.size(); i++)
            {
                table[s.substr(0, i)]++;
            }
        }

        int _ans;
        vector<int> ans;
        for (const auto &s : words)
        {
            _ans = 0;
            for (int i = 1; i <= s.size(); i++)
            {
                _ans += table[s.substr(0, i)];
            }
            ans.push_back(_ans);
        }

        return ans;
    }
};
