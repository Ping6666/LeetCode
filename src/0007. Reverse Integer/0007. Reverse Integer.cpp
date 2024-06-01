#include <string>
using namespace std;

class Solution
{
    // Runtime: 0 ms (100.00 %), Memory: 5.9 MB (76.18 %).
public:
    int reverse(int x)
    {
        if (!x)
            return 0;
        int ans = 0;
        int pCheck = x > 0 ? 1 : -1;
        x = abs(x);
        while (!!x)
        {
            if (abs(ans) >= 214748365)
                return 0;
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        return ans * pCheck;
    }
};

/*
class Solution
{
    // Runtime: 0 ms (100 %), Memory: 6.4 MB (5.96 %).
public:
    int reverse(int x)
    {
        int positiveNumber = x >= 0 ? 1 : -1;
        string intstring = to_string(abs(x));
        string intreversestring(intstring.rbegin(), intstring.rend());
        try
        {
            return stoi(intreversestring) * positiveNumber;
        }
        catch (exception &e)
        {
            return 0;
        }
    }
};
*/
