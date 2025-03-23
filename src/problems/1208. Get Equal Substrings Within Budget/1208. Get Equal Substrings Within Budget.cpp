#include <string>
#include <queue>

class Solution
{
    // Runtime: 3 ms (97.07 %), Memory: 8.69 MB (93.85 %).
public:
    int equalSubstring(std::string s, std::string t, int maxCost)
    {
        int ii = 0;

        int accum_d = 0;
        int accum_l = 0;

        int max_l = 0;

        int l = s.size();
        for (int i = 0; i < l; i++)
        {
            int d = abs(s[i] - t[i]);

            while (accum_l > 0 && accum_d + d > maxCost)
            {
                accum_d -= abs(s[ii] - t[ii]);
                ii += 1;

                accum_l--;
            }

            if (accum_d + d <= maxCost)
            {
                accum_d += d;

                accum_l++;

                if (accum_l > max_l)
                {
                    max_l = accum_l;
                }
            }
            else
            {
                ii += 1;
            }
        }

        return max_l;
    }
};

/*
class Solution
{
    // Runtime: 3 ms (97.07 %), Memory: 9.52 MB (7.76 %).
public:
    int equalSubstring(std::string s, std::string t, int maxCost)
    {
        int accum_d = 0;
        int accum_l = 0;

        int max_l = 0;

        std::queue<int> q;

        int l = s.size();
        for (int i = 0; i < l; i++)
        {
            int d = s[i] - t[i];
            if (d < 0)
            {
                d *= -1;
            }

            while (accum_l > 0 && accum_d + d > maxCost)
            {
                accum_d -= q.front();
                q.pop();

                accum_l--;
            }

            if (accum_d + d <= maxCost)
            {
                accum_d += d;
                q.push(d);

                accum_l++;

                if (accum_l > max_l)
                {
                    max_l = accum_l;
                }
            }
        }

        return max_l;
    }
};
*/
