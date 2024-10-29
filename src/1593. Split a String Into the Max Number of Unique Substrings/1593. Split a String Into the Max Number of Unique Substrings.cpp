#include <string>
#include <unordered_set>
using std::string, std::unordered_set;

// Runtime: 15 ms (Beats 99.42 %), Memory: 12.59 MB (Beats 97.66 %).

class Solution
{
private:
    void backtrack(string &s, unordered_set<string> &seen, int start, int count, int &max_count)
    {
        if (count + (s.size() - start) <= max_count)
        {
            // can not exceed the max_count
            return;
        }

        if (start == s.size())
        {
            // reach the end, then update
            max_count = max(max_count, count);
            return;
        }

        for (int end = start + 1; end <= s.size(); end++)
        {
            string sub = s.substr(start, end - start);
            if (seen.find(sub) == seen.end())
            {
                // can add
                seen.insert(sub);

                backtrack(s, seen, end, count + 1, max_count);

                seen.erase(sub);
            }
        }
    }

public:
    int maxUniqueSplit(string s)
    {
        unordered_set<string> seen;
        int ans = 0;

        backtrack(s, seen, 0, 0, ans);

        return ans;
    }
};
