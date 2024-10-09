#include <string>
using std::string;

// Runtime: 3 ms (Beats 94.61 %), Memory: 8.44 MB (Beats 99.89 %).

bool isZeroArr(int *arr)
{
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
        {
            return false;
        }
    }
    return true;
}

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int l1 = s1.size(), l2 = s2.size();
        if (l2 < l1)
        {
            return false;
        }

        int arr[26] = {0};
        for (int i = 0; i < l1; i++)
        {
            arr[s1[i] - 'a']++;
        }

        for (int i = 0; i < l2; i++)
        {
            arr[s2[i] - 'a']--;

            if (i - l1 >= 0)
            {
                arr[s2[i - l1] - 'a']++;
            }

            if (isZeroArr(arr))
            {
                return true;
            }
        }

        return false;
    }
};
