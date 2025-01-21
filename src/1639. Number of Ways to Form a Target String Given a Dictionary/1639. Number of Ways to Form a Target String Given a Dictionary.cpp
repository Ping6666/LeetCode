#include <vector>
#include <string>
using std::vector, std::string;

// Runtime: 51 ms (Beats 83.21 %), Memory: 32.72 MB (Beats 92.21 %).

// ref.: LeetCode Editorial - Approach 3: Optimized Bottom-up Dynamic Programmning

class Solution
{
public:
    int numWays(vector<string> &words, string target)
    {
        const int _mod = 1000000007;

        int word_len = words[0].size();
        int target_len = target.size();

        vector<vector<int>> freq(word_len, vector<int>(26, 0));
        for (const auto &w : words)
        {
            for (int i = 0; i < word_len; i++)
            {
                freq[i][w[i] - 'a']++;
            }
        }

        vector<long> _curr(target_len + 1, 0);
        vector<long> _prev(target_len + 1, 0);

        int c;
        _prev[0] = 1;

        for (int i = 0; i < word_len; i++)
        {
            _curr = _prev;
            for (int j = 0; j < target_len; j++)
            {
                c = target[j] - 'a';

                _curr[j + 1] += (freq[i][c] * _prev[j]) % _mod;
                _curr[j + 1] %= _mod;
            }
            _prev = _curr;
        }

        return _curr[target_len];
    }
};
