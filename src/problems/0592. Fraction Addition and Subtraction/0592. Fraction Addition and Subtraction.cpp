#include <string>
#include <vector>
#include <numeric>
using std::string, std::vector, std::pair, std::gcd;

// Runtime: 0 ms (Beats 100.00 %), Memory: 7.80 MB (Beats 34.88 %).

class Solution
{
private:
    void getFrac(pair<int, int> &p)
    {
        // irreducible fraction
        if (p.first == 0)
        {
            p.second = 1;
            return;
        }

        int d = gcd(p.first, p.second);

        p.first /= d;
        p.second /= d;
        return;
    }

    int getNumber(string str, int idx)
    {
        int n = str.size();

        int ans = 0;
        while (idx < n)
        {
            if (str[idx] - '0' >= 0 && str[idx] - '0' < 10)
            {
                ans *= 10;
                ans += str[idx] - '0';
            }
            else
            {
                break;
            }

            idx++;
        }

        return ans;
    }

public:
    string fractionAddition(string expression)
    {
        vector<pair<int, int>> vec;

        int n = expression.size();
        for (int i = 0; i < n;)
        {
            bool neg = false;
            if (expression[i] == '-')
            {
                neg = true;
                i++;
            }
            else if (expression[i] == '+')
            {
                i++;
            }

            int numerator = getNumber(expression, i);
            if (neg)
            {
                numerator *= -1;
            }

            while (expression[i] != '/')
            {
                i++;
            }

            int denominator = getNumber(expression, ++i);

            while (expression[i] != '-' && expression[i] != '+' && i < n)
            {
                i++;
            }

            vec.emplace_back(numerator, denominator);
        }

        for (int i = 1; i < vec.size(); i++)
        {
            int d = gcd(vec[0].second, vec[i].second);

            vec[0].first *= vec[i].second / d;
            vec[i].first *= vec[0].second / d;

            vec[0].first += vec[i].first;
            vec[0].second *= vec[i].second / d;

            getFrac(vec[0]);
        }

        if (vec[0].first == 0)
        {
            return "0/1";
        }

        string s;
        s += std::to_string(vec[0].first);
        s += '/';
        s += std::to_string(vec[0].second);

        return s;
    }
};
