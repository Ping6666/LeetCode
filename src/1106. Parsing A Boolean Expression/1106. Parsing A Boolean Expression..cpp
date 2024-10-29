#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 8.17 MB (Beats 99.82 %).

class Solution
{
private:
    bool parse_not(string &expression, int idx)
    {
        return !parser(expression, idx + 1);
    }

    bool parse_and(string &expression, int idx)
    {
        int counter = 0;

        bool ans = true;
        while (true)
        {
            // printf("and %d %c\n", idx, expression[idx]);
            if (expression[idx] == '(')
            {
                counter++;
            }
            else if (expression[idx] == ')')
            {
                counter--;

                if (counter == 0)
                {
                    break;
                }
            }
            else if ((idx > 0) && (counter == 1) &&
                     (expression[idx - 1] == '(' ||
                      expression[idx - 1] == ','))
            {
                ans &= parser(expression, idx);

                if (!ans)
                {
                    // early stop
                    break;
                }
            }
            idx++;
        }

        return ans;
    }

    bool parse_or(string &expression, int idx)
    {
        int counter = 0;

        bool ans = false;
        while (true)
        {
            // printf("or %d %c\n", idx, expression[idx]);
            if (expression[idx] == '(')
            {
                counter++;
            }
            else if (expression[idx] == ')')
            {
                counter--;

                if (counter == 0)
                {
                    break;
                }
            }
            else if ((idx > 0) && (counter == 1) &&
                     (expression[idx - 1] == '(' ||
                      expression[idx - 1] == ','))
            {
                ans |= parser(expression, idx);
            }
            idx++;
        }

        return ans;
    }

    bool parser(string &expression, int idx)
    {
        if (expression[idx] == 't')
        {
            return true;
        }
        else if (expression[idx] == 'f')
        {
            return false;
        }
        else if (expression[idx] == '!')
        {
            return parse_not(expression, idx + 1);
        }
        else if (expression[idx] == '&')
        {
            return parse_and(expression, idx + 1);
        }
        else if (expression[idx] == '|')
        {
            return parse_or(expression, idx + 1);
        }

        return false;
    }

public:
    bool parseBoolExpr(string expression)
    {
        return parser(expression, 0);
    }
};
