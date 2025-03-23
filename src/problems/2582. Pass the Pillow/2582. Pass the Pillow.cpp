// Runtime: 0 ms (Beats 100.00 %), Memory: 6.90 MB (Beats 96.49 %).

class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int shift = time % (n - 1);

        if ((time / (n - 1)) % 2)
        {
            // rev.
            return n - shift;
        }
        return shift + 1;
    }
};
