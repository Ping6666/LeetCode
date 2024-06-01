#include <string>
using std::string;

class Solution
{
    // Runtime: 0 ms (Beats 100.00 %), Memory: 7.68 MB (Beats 97.38 %).
    // Time Complexity: O(N), Space Complexity: O(1)

public:
    int scoreOfString(string s)
    {
        if (s.length() < 2)
        {
            return 0;
        }

        int score = 0;
        char prev_c = s[0];
        for (auto curr_c : s)
        {
            score += abs(prev_c - curr_c);
            prev_c = curr_c;
        }

        return score;
    }
};
