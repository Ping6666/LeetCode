// Runtime: 0 ms (Beats 100.00 %), Memory: 7.20 MB (Beats 97.21 %).

class Solution
{
private:
    int checkCount(int n, long _curr)
    {
        long _next = _curr + 1;
        int count = 0;

        while (_curr <= n)
        {
            count += min((long)(n + 1), _next) - _curr;
            _curr *= 10;
            _next *= 10;
        }

        return count;
    }

public:
    int findKthNumber(int n, int k)
    {
        int num = 1, step;
        k--;

        while (k > 0)
        {
            step = checkCount(n, num);

            if (step <= k)
            {
                // in range can add
                num++;
                k -= step;
            }
            else
            {
                num *= 10;
                k--;
            }
        }

        return num;
    }
};
