// Runtime: 0 ms (Beats 100.00 %), Memory: 7.38 MB (Beats 99.69 %).

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int ans = 0;
        while (start > 0 || goal > 0)
        {
            if (start % 2 != goal % 2)
            {
                ans++;
            }
            start /= 2;
            goal /= 2;
        }

        return ans;
    }
};
