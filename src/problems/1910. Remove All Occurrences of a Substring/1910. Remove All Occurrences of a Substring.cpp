#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using std::string, std::vector, std::stack, std::reverse;

// Runtime: 0 ms (Beats 100.00 %), Memory: 10.16 MB (Beats 11.47 %).
// ref: LeetCode Editorial - Approach 3: Knuth-Morris-Pratt (KMP) Algorithm

class Solution
{
private:
    vector<int> computeLongestPrefixSuffix(string pattern)
    {
        int n = pattern.size();
        vector<int> lps(n, 0);

        for (int i = 1, l = 0; i < n;)
        {
            if (pattern[i] == pattern[l])
            {
                // match then inc. the len.
                l++;
                lps[i] = l;
                i++;
            }
            else if (l != 0)
            {
                // try to check prev. longest prefix-suffix
                l = lps[l - 1];
            }
            else
            {
                // not found, reset
                lps[i] = 0;
                i++;
            }
        }
        return lps;
    }

public:
    string removeOccurrences(string s, string part)
    {
        const int n = s.size(), m = part.size();
        vector<int> kmp_lps = computeLongestPrefixSuffix(part);

        stack<char> _stack;
        vector<int> pattern_idx(n + 1);

        for (int i = 0, p_idx = 0; i < n; i++)
        {
            _stack.push(s[i]);

            if (s[i] == part[p_idx])
            {
                pattern_idx[_stack.size()] = ++p_idx;

                if (p_idx == m)
                {
                    // match all

                    int l = m;
                    while (l > 0)
                    {
                        _stack.pop();
                        l--;
                    }

                    p_idx = _stack.empty() ? 0 : pattern_idx[_stack.size()];
                }
            }
            else
            {
                // not match try to backtrack
                if (p_idx != 0)
                {
                    i--;
                    _stack.pop();
                    p_idx = kmp_lps[p_idx - 1];
                }
                else
                {
                    // nothing there, reset
                    pattern_idx[_stack.size()] = 0;
                }
            }
        }

        string ans = "";
        while (!_stack.empty())
        {
            ans += _stack.top();
            _stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
