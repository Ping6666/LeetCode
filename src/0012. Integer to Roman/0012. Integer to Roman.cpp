#include <string>
using namespace std;

class Solution
{
    // Runtime: 0 ms (100.00 %), Memory: 5.9 MB (92.25 %).
public:
    string intToRoman(int num)
    {
        string ansStr;
        int counter = 0;
        char tableRoman[4][3] = {{'I', 'V', 'X'}, {'X', 'L', 'C'}, {'C', 'D', 'M'}, {'M', NULL, NULL}};
        while (num > 0)
        {
            switch (num % 10)
            {
            case 1:
                ansStr = tableRoman[counter][0] + ansStr;
                break;
            case 2:
                ansStr = tableRoman[counter][0] + ansStr;
                ansStr = tableRoman[counter][0] + ansStr;
                break;
            case 3:
                ansStr = tableRoman[counter][0] + ansStr;
                ansStr = tableRoman[counter][0] + ansStr;
                ansStr = tableRoman[counter][0] + ansStr;
                break;
            case 4:
                ansStr = tableRoman[counter][1] + ansStr;
                ansStr = tableRoman[counter][0] + ansStr;
                break;
            case 5:
                ansStr = tableRoman[counter][1] + ansStr;
                break;
            case 6:
                ansStr = tableRoman[counter][0] + ansStr;
                ansStr = tableRoman[counter][1] + ansStr;
                break;
            case 7:
                ansStr = tableRoman[counter][0] + ansStr;
                ansStr = tableRoman[counter][0] + ansStr;
                ansStr = tableRoman[counter][1] + ansStr;
                break;
            case 8:
                ansStr = tableRoman[counter][0] + ansStr;
                ansStr = tableRoman[counter][0] + ansStr;
                ansStr = tableRoman[counter][0] + ansStr;
                ansStr = tableRoman[counter][1] + ansStr;
                break;
            case 9:
                ansStr = tableRoman[counter][2] + ansStr;
                ansStr = tableRoman[counter][0] + ansStr;
                break;
            case 0:
                break;
            default:
                break;
            }
            counter++;
            num /= 10;
        }
        return ansStr;
    }
};
