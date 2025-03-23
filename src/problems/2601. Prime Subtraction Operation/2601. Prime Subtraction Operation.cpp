#include <vector>
using std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 26.58 MB (Beats 99.36 %).

class Solution
{
private:
    bool isPrime(int x)
    {
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                return false;
            }
        }
        return true;
    }

public:
    bool primeSubOperation(vector<int> &nums)
    {
        int n = nums.size();

        int _p = 0, t;
        for (int i = 0; i < n; i++)
        {
            t = nums[i] - _p;
            if (t <= 0)
            {
                return false;
            }

            _p = nums[i];
            for (int j = t - 1; j >= 2; j--)
            {
                if (isPrime(j))
                {
                    _p = nums[i] - j;
                    break;
                }
            }
        }

        return true;
    }
};
