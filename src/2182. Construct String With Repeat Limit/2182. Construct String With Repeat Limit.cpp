#include <string>
using std::string, std::min;

// Runtime: 3 ms (Beats 98.73 %), Memory: 27.64 MB (Beats 59.07 %).

class Solution
{
private:
    int get_next(int *char_freq, int idx)
    {
        // return next idx where char freq is not zero

        for (int i = idx - 1; i >= 0; i--)
        {
            if (char_freq[i] != 0)
            {
                return i;
            }
        }

        return -1;
    }

public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        int char_freq[26] = {0};

        for (const auto &c : s)
        {
            char_freq[c - 'a']++;
        }

        int char1_idx = get_next(char_freq, 26);
        int char2_idx = get_next(char_freq, char1_idx);

        bool use_char1 = true;
        string new_s = "";

        int c;
        while (true)
        {
            if (use_char1)
            {
                if (char1_idx == -1)
                {
                    break;
                }

                c = min(char_freq[char1_idx], repeatLimit);
                char_freq[char1_idx] -= c;

                // new_s += string(c, 'a' + char1_idx);
                for (int i = 0; i < c; i++)
                {
                    new_s += 'a' + char1_idx;
                }

                if (char_freq[char1_idx] == 0)
                {
                    char1_idx = char2_idx;
                    char2_idx = get_next(char_freq, char1_idx);
                    use_char1 = true;
                }
                else
                {
                    use_char1 = false;
                }
            }
            else
            {
                if (char2_idx == -1)
                {
                    break;
                }

                // greedy
                c = min(char_freq[char2_idx], 1);
                char_freq[char2_idx] -= c;

                // new_s += string(c, 'a' + char2_idx);
                for (int i = 0; i < c; i++)
                {
                    new_s += 'a' + char2_idx;
                }

                if (char_freq[char2_idx] == 0)
                {
                    char2_idx = get_next(char_freq, char1_idx);
                    use_char1 = true;
                }
                else
                {
                    use_char1 = true;
                }
            }
        }

        return new_s;
    }
};
