#include <string>

using std::string;

// Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

class Solution
{
public:
    string reverseWords(string s)
    {
        int len = s.size();

        int insert_pos = 0;
        int last_char_pos = len;

        bool got_word = false;
        for (int i = len - 1; i >= 0; i--)
        {
            if (!got_word && s[i] != ' ')
            {
                if (i < insert_pos)
                {
                    break;
                }
                last_char_pos = i;
                got_word = true;
            }
            else if (got_word && s[i] == ' ')
            {
                // word = i + 1 ~ last_char_pos
                int add_len = last_char_pos - i;

                s.insert(insert_pos, s.substr(i + 1, add_len) + " ");
                insert_pos += add_len + 1;

                i += add_len + 1;
                got_word = false;
            }
        }

        // special case
        if (insert_pos == 0)
        {
            int l = -1;
            for (int i = len - 1; i >= 0; i--)
            {
                if (s[i] != ' ')
                {
                    l = i;
                    break;
                }
            }
            return s.substr(0, l + 1);
        }

        return s.substr(0, insert_pos - 1);
    }
};
