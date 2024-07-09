// Runtime: 0 ms (Beats 100.00 %), Memory: 7.01 MB (Beats 72.30 %).

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int num = 0, numEmpty = 0;
        while (numBottles > 0 || numEmpty >= numExchange)
        {
            num += numBottles;
            numEmpty += numBottles;

            numBottles = numEmpty / numExchange;
            numEmpty %= numExchange;
        }

        return num;
    }
};
