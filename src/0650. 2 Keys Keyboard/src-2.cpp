// Runtime: 0 ms (Beats 100.00 %), Memory: 7.26 MB (Beats 80.37 %).
// write backtracking (division) into while loop

class Solution
{
public:
    int minSteps(int n)
    {
        int ans = 0;
        int d = 2;

        while (n > 1)
        {
            while (n % d == 0)
            {
                ans += d;
                n /= d;
            }

            d++;
        }

        return ans;
    }
};
