#include <string>
using std::string;

// Fail to use MAGIC

class Solution
{
public:
    string nearestPalindromic(string n)
    {
        int _size = n.size();
        int half_size = _size / 2;

        if (_size > 1 and n[0] == '1')
        {
            bool ten_power = true;
            for (int i = 1; i < _size; i++)
            {
                if (n[i] != '0')
                {
                    ten_power = false;
                    break;
                }
            }

            if (ten_power)
            {
                n = "";
                for (int i = 0; i < _size - 1; i++)
                {
                    n += "9";
                }
                return n;
            }
        }

        if (_size == 1)
        {
            int _n = n[0] - '0';
            if (_n == 0)
            {
                return "1";
            }
            else
            {
                return std::to_string(_n - 1);
            }
        }

        bool is_palindrome = true;
        bool all_nine = true;
        bool all_one = true;
        for (int i = 0; i < half_size; i++)
        {
            if (is_palindrome)
            {
                if (n[_size - 1 - i] != n[i])
                {
                    is_palindrome = false;
                    all_nine = false;
                    all_one = false;
                }
                else
                {
                    if (all_nine)
                    {
                        if (n[i] != '9')
                        {
                            all_nine = false;
                        }
                    }
                    if (all_one)
                    {
                        if (n[i] != '1')
                        {
                            all_one = false;
                        }
                    }
                }
            }
            n[_size - 1 - i] = n[i];
        }

        if (!is_palindrome)
        {
            return n;
        }

        // if itself is already a palindrome (change it)
        if (_size % 2 == 1)
        {
            // odd len.
            int _mid = n[half_size] - '0';
            if (_mid == 9 && all_nine)
            {
                n = "1";
                for (int i = 0; i < _size - 1; i++)
                {
                    n += "0";
                }
                n += "1";
                return n;
            }
            else if (_mid == 0 && all_one)
            {
                n = "";
                for (int i = 0; i < _size - 1; i++)
                {
                    n += "9";
                }
                return n;
            }

            if (_mid > 0)
            {
                n[half_size] -= 1;
            }
            else
            {
                n[half_size] += 1;
            }
        }
        else
        {
            if (all_nine)
            {
                n = "1";
                for (int i = 0; i < _size - 1; i++)
                {
                    n += "0";
                }
                n += "1";
                return n;
            }
            if (all_one)
            {
                n = "";
                for (int i = 0; i < _size - 1; i++)
                {
                    n += "9";
                }
                return n;
            }

            // even len.
            int _mid = n[half_size] - '0';

            if (_mid != 0 && _mid != 9)
            {
                n[half_size] -= 1;
                n[half_size - 1] -= 1;
            }
            else if (_mid == 0)
            {
                // 0
                int i = half_size - 1;

                for (; i >= 0; i--)
                {
                    if (n[i] == '0')
                    {
                        n[i] = '9';
                        n[_size - 1 - i] = '9';
                    }
                    else
                    {
                        break;
                    }
                }

                for (; i >= 0; i--)
                {
                    if (n[i] == '0')
                    {
                        n[i] = '9';
                        n[_size - 1 - i] = '9';
                    }
                    else
                    {
                        n[i] -= 1;
                        n[_size - 1 - i] -= 1;

                        if (i == 0 && n[i] == '0')
                        {
                            n.erase(n.begin() + _size - 1);
                            n.erase(n.begin());
                            n += '9';
                            return n;
                        }
                        break;
                    }
                }
            }
            else
            {
                // 9
                int i = half_size - 1;

                for (; i >= 0; i--)
                {
                    if (n[i] == '9')
                    {
                        n[i] = '0';
                        n[_size - 1 - i] = '0';
                    }
                    else
                    {
                        break;
                    }
                }

                for (int i = half_size - 2; i >= 0; i--)
                {
                    if (n[i] == '9')
                    {
                        n[i] = '0';
                        n[_size - 1 - i] = '0';
                    }
                    else
                    {
                        n[i] += 1;
                        n[_size - 1 - i] += 1;
                        break;
                    }
                }
            }
        }

        return n;
    }
};
