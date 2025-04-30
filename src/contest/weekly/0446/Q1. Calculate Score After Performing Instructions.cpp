#include <vector>
#include <string>
#include <unordered_set>
using std::vector, std::string, std::unordered_set;

class Solution
{
public:
    long long calculateScore(vector<string> &instructions, vector<int> &values)
    {
        const int n = values.size();
        int i = 0;

        unordered_set<int> visited;
        long long ans = 0;
        while (i >= 0 && i < n)
        {
            if (visited.find(i) != visited.end())
            {
                break;
            }
            visited.insert(i);

            if (instructions[i] == "add")
            {
                // add
                ans += values[i];
                i += 1;
            }
            else
            {
                // jump
                i += values[i];
            }
        }
        return ans;
    }
};
