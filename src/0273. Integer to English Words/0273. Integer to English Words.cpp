#include <string>
#include <vector>
using std::string, std::vector;

// Runtime: 0 ms (Beats 100.00 %), Memory: 10.22 MB (Beats 79.39 %).

class Solution
{
public:
    string numberToWords(int num)
    {
        string arr_1[20] = {
            //
            "Zero",
            //
            "One",
            "Two",
            "Three",
            "Four",
            "Five",
            //
            "Six",
            "Seven",
            "Eight",
            "Nine",
            "Ten",
            //
            "Eleven",
            "Twelve",
            "Thirteen",
            "Fourteen",
            "Fifteen",
            //
            "Sixteen",
            "Seventeen",
            "Eighteen",
            "Nineteen",
        };
        string arr_2[10] = {
            "Zero",
            "Ten",
            "Twenty",
            "Thirty",
            "Forty",
            "Fifty",
            "Sixty",
            "Seventy",
            "Eighty",
            "Ninety",
        };
        string arr_3[4] = {
            "Zero",
            "Thousand",
            "Million",
            "Billion",
        };

        if (num < 20)
        {
            return arr_1[num];
        }

        vector<int> nums;
        while (num > 0)
        {
            nums.push_back(num % 1000);
            num /= 1000;
        }

        vector<string> ans_vec;
        for (const auto &n : nums)
        {
            int _n = n;
            string s = "";

            if (n >= 100)
            {
                s += arr_1[_n / 100] + " Hundred";
            }
            _n %= 100;

            if (_n >= 20)
            {
                if (s.size() > 0)
                {
                    s += " ";
                }
                s += arr_2[_n / 10];
                _n %= 10;

                if (_n > 0)
                {
                    s += " " + arr_1[_n];
                }
            }
            else if (_n > 0)
            {
                if (s.size() > 0)
                {
                    s += " ";
                }
                s += arr_1[_n];
            }

            ans_vec.push_back(s);
        }

        string ans = "";
        for (int i = ans_vec.size() - 1; i >= 0; i--)
        {
            if (nums[i] > 0)
            {
                if (ans.size() > 0)
                {
                    ans += " ";
                }

                ans += ans_vec[i];
                if (i != 0)
                {
                    ans += " " + arr_3[i];
                }
            }
        }

        return ans;
    }
};
