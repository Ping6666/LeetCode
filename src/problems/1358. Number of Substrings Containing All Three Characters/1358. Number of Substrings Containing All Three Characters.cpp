#include <string>
using std::string;

// Runtime: 1 ms (Beats 94.32 %), Memory: 10.83 MB (Beats 94.17 %).

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        const int n = s.size();
        int l = 0, r = 0;

        int char_freq[3] = {0};
        int num_char = 0;

        int ans = 0;
        while (r < n)
        {
            // add s[r]

            if (char_freq[s[r] - 'a']++ == 0)
            {
                num_char++;
            }

            // try to shrink

            while (num_char == 3)
            {
                if (char_freq[s[l] - 'a'] > 1)
                {
                    // can shrink
                    char_freq[s[l] - 'a']--;
                    l++;
                }
                else
                {
                    break;
                }
            }

            if (num_char == 3)
            {
                // ans += n - (r - l);
                ans += l + 1;
                // printf("%d %d %d %d\n", n, r, l, n - (r - l));
            }

            r++;
        }
        return ans;
    }
};
