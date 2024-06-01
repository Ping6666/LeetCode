#include <stack>
#include <string>
using namespace std;

class Solution
{
    // Runtime: 0 ms (100.00 %), Memory: 6.2 MB (79.28 %).
public:
    bool isValid(string s)
    {
        stack<char> validInput;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                validInput.push(s[i]);
            }
            else
            {
                if (!validInput.empty() && ((validInput.top() == '(' && s[i] == ')') || (validInput.top() == '[' && s[i] == ']') || (validInput.top() == '{' && s[i] == '}')))
                {
                    validInput.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return validInput.empty();
    }
};