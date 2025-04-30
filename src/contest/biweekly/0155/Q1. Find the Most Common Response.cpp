#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
using std::string, std::vector, std::set, std::unordered_set, std::unordered_map, std::max;

class Solution
{
public:
    string findCommonResponse(vector<vector<string>> &responses)
    {
        int _max = 0;
        unordered_map<string, int> m;
        for (const auto &res : responses)
        {
            unordered_set<string> s;
            for (const auto r : res)
            {
                s.insert(r);
            }
            for (const auto ss : s)
            {
                m[ss]++;

                if (m[ss] > _max)
                {
                    _max = m[ss];
                }
            }
        }

        set<string> ans_s;
        for (const auto mm : m)
        {
            if (_max == mm.second)
            {
                ans_s.insert(mm.first);
            }
        }

        return *ans_s.begin();
    }
};
