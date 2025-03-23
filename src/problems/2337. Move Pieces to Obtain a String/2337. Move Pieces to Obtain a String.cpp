#include <string>
using std::string;

// Runtime: 0 ms (Beats 100.00 %), Memory: 21.73 MB (Beats 37.84 %).

class Solution
{
public:
    bool canChange(string start, string target)
    {
        int n = start.size();

        int s_idx = 0, t_idx = 0;
        bool check;

        while (s_idx < n && t_idx < n)
        {
            if (target[t_idx] == 'L')
            {
                // try to get L in start
                check = false;

                while (s_idx < t_idx)
                {
                    if (start[s_idx++] != '_')
                    {
                        return false;
                    }
                }

                while (s_idx < n)
                {
                    if (start[s_idx] == '_')
                    {
                        s_idx++;
                    }
                    else if (start[s_idx] == 'L')
                    {
                        s_idx++;
                        check = true;
                        break;
                    }
                    else
                    {
                        // printf("AAA");
                        return false;
                    }
                }

                if (!check)
                {
                    // printf("BBB");
                    return false;
                }
            }
            else if (target[t_idx] == 'R')
            {
                // try to get R in start
                check = false;

                while (s_idx <= t_idx)
                {
                    if (start[s_idx] == '_')
                    {
                        s_idx++;
                    }
                    else if (start[s_idx] == 'R')
                    {
                        s_idx++;
                        check = true;
                        break;
                    }
                    else
                    {
                        // printf("CCC");
                        return false;
                    }
                }

                if (!check)
                {
                    // printf("DDD");
                    return false;
                }
            }

            t_idx++;
        }

        while (t_idx < n)
        {
            if (target[t_idx++] != '_')
            {
                // printf("EEE");
                return false;
            }
        }
        while (s_idx < n)
        {
            if (start[s_idx++] != '_')
            {
                // printf("FFF");
                return false;
            }
        }

        return true;
    }
};
