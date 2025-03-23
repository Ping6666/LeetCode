#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <map>
using std::string, std::vector, std::stack, std::map;

// Runtime: 0 ms (Beats 100.00 %), Memory: 8.92 MB (Beats 73.53 %).

class Solution
{
private:
    int getNumber(string &s, int i, int j)
    {
        // in range [i, j]

        int ii = i;
        while (ii <= j)
        {
            if (s[ii] - '0' >= 0 && s[ii] - '0' <= 9)
            {
                // is num
                ii++;
            }
            else
            {
                break;
            }
        }

        if (ii - i == 0)
        {
            return 1;
        }

        return atoi(s.substr(i, ii - i).c_str());
    }

    void preprocessScaler(string &s, vector<int> &res)
    {
        stack<int> idx;

        int n = s.size();
        res.resize(n);

        int v;

        for (int i = 0; i < n; i++)
        {
            res[i] = 1;

            if (s[i] == '(')
            {
                idx.push(i);
            }
            else if (s[i] == ')')
            {
                v = getNumber(s, i + 1, n - 1);

                for (int j = idx.top(); j <= i; j++)
                {
                    res[j] *= v;
                }
                idx.pop();
            }
        }
    }

    int getCharLen(string &s, int i, int j)
    {
        // in range [i, j]

        int ii = i;
        while (ii <= j)
        {
            if (s[ii] - 'a' >= 0 && s[ii] - 'a' <= 25)
            {
                // is num
                ii++;
            }
            else
            {
                break;
            }
        }

        return ii - i;
    }

    void parser(string &s, vector<int> &scaler, map<string, int> &res)
    {
        int n = s.size();

        int j, v;

        for (int i = 0; i < n; i++)
        {
            if (s[i] - 'A' >= 0 && s[i] - 'A' <= 25)
            {
                j = getCharLen(s, i + 1, n - 1);
                v = getNumber(s, i + j + 1, n - 1);
                res[s.substr(i, j + 1)] += v * scaler[i];

                i = i + j;
            }
        }
    }

public:
    string countOfAtoms(string formula)
    {
        vector<int> scaler;
        preprocessScaler(formula, scaler);

        for (auto c : scaler)
        {
            printf("%d ", c);
        }

        map<string, int> table;
        parser(formula, scaler, table);

        string s;
        for (const auto &i : table)
        {
            s += i.first;

            if (i.second > 1)
            {
                s += std::to_string(i.second);
            }
        }

        return s;
    }
};
