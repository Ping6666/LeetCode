#include <string>
#include <vector>
using namespace std;

class Solution
{
    // algorithm: divide and conquer

    // Time complexity:
    // O( n ) = O( 0 ) * O( n-1 ) + O( 1 ) * O( n-2 ) + ... + O( n-1 ) * O( 0 )
    // O( 0 ) = 1
    // Runtime: 0 ms (100.00 %), Memory: 12.3 MB (70.29 %).

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ansVector;
        if (n == 0)
        {
            ansVector.push_back("");
            return ansVector;
        }
        for (int i = 0; i < n; i++)
        {
            // 0, 1, 2, ... n - 1
            vector<string> left, right;
            left = generateParenthesis(i);
            right = generateParenthesis(n - i - 1);
            for (int iLeft = 0; iLeft < left.size(); iLeft++)
            {
                for (int iRight = 0; iRight < right.size(); iRight++)
                {
                    ansVector.push_back("(" + left[iLeft] + ")" + right[iRight]);
                }
            }
        }
        return ansVector;
    }
};
