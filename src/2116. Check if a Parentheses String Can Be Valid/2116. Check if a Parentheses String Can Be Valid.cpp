#include <string>
#include <stack>
using std::string, std::stack;

// Runtime: 15 ms (Beats 51.52 %), Memory: 32.29 MB (Beats 30.96 %).

class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        int n = s.size();
        if (n % 2 != 0)
        {
            return false;
        }

        stack<char> _stack;
        bool _push;

        char t;
        int can_flip = 0;
        int space_count = 0; // speed up

        for (int i = 0; i < n; i++)
        {
            if (locked[i] == '1')
            {
                // is locked

                _push = true;
                if (s[i] == ')')
                {
                    if (!_stack.empty())
                    {
                        t = _stack.top();
                        if (t == ' ' || t == '(')
                        {
                            _stack.pop();
                            _push = false;
                            if (t == ' ')
                            {
                                space_count--;
                            }
                        }
                    }

                    if (_push)
                    {
                        if (can_flip > 0)
                        {
                            // important to solve the BUG using greedy
                            can_flip--;
                            s[i] = '(';
                        }
                        else
                        {
                            return false;
                        }
                    }
                }

                if (_push)
                {
                    _stack.push(s[i]);
                }
            }
            else
            {
                // is not locked

                _push = true;
                if (!_stack.empty())
                {
                    t = _stack.top();
                    if (t == '(')
                    {
                        _stack.pop();
                        _push = false;
                        can_flip++;
                    }
                }

                if (_push)
                {
                    _stack.push(' ');
                    space_count++;
                }
            }
        }

        if (_stack.size() > space_count)
        {
            return false;
        }
        // while (!_stack.empty())
        // {
        //     t = _stack.top();
        //     _stack.pop();
        //     // printf("%c\n", t);

        //     if (t != ' ')
        //     {
        //         return false;
        //     }
        // }
        return true;
    }
};
