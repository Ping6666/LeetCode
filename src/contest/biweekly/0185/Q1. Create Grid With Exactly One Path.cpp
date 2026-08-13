#include <vector>
#include <string>

using std::vector, std::string;

class Solution
{
public:
    vector<string> createGrid(int m, int n)
    {
        vector<string> ans = vector<string>();
        ans.push_back(string(n, '.'));
        for (int i = 0; i < m - 1; i++)
            ans.push_back(string(n - 1, '#') + string(1, '.'));
        return ans;
    }
};
