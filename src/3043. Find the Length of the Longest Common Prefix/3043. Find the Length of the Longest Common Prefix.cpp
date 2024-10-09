#include <vector>
#include <unordered_set>
using std::vector, std::unordered_set;

// Runtime: 252 ms (Beats 74.24 %), Memory: 134.73 MB (Beats 99.07 %).

class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_set<int> table;

        int n;
        for (int i = 0; i < arr1.size(); i++)
        {
            n = arr1[i];
            if (n == 0)
            {
                table.insert(n);
            }

            while (n > 0)
            {
                table.insert(n);

                n /= 10;
            }
        }

        int l = 0, _l;
        for (int i = 0; i < arr2.size(); i++)
        {
            n = arr2[i];
            if (n == 0)
            {
                if (table.find(n) != table.end())
                {
                    l = max(l, 1);
                }
            }

            while (n > 0)
            {
                if (table.find(n) != table.end())
                {
                    _l = 0;
                    while (n > 0)
                    {
                        _l++;
                        n /= 10;
                    }

                    l = max(l, _l);
                    break;
                }
                n /= 10;
            }
        }

        return l;
    }
};
