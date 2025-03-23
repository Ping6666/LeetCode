#include <string>
#include <vector>
using std::string, std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 97.71 MB (Beats 78.95 %).

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.size();
        vector<int> shift_table(n, 0);

        int t;
        for (const auto &shift : shifts)
        {
            t = shift[1] + 1;
            if (shift[2] == 1)
            {
                // forward
                shift_table[shift[0]]++;

                if (t < n)
                {
                    shift_table[t]--;
                }
            }
            else
            {
                // backward
                shift_table[shift[0]]--;

                if (t < n)
                {
                    shift_table[t]++;
                }
            }
        }

        int _shift = 0;
        for (int i = 0; i < n; i++)
        {
            _shift += shift_table[i];

            t = s[i] - 'a';
            t += _shift;
            t %= 26;
            if (t < 0)
            {
                t += 26;
            }
            s[i] = t + 'a';
        }
        return s;
    }
};

/*
// TLE

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.size(), t, _shift;
        int z_next = 'z' + 1, a_prev = 'a' - 1;
        for (const auto &shift : shifts)
        {
            _shift = shift[2] == 1 ? 1 : -1;
            for (int i = shift[0]; i <= shift[1]; i++)
            {
                s[i] += _shift;
                if (s[i] == z_next)
                {
                    s[i] = 'a';
                }
                else if (s[i] == a_prev)
                {
                    s[i] = 'z';
                }
            }
        }
        return s;
    }
};
*/
