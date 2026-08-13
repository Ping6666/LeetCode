#include <vector>

using std::vector;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
        {
            return true;
        }

        int len = flowerbed.size();
        int prev_idx = -1;
        for (int i = 0; i < len; i++)
        {
            if (flowerbed[i] == 0)
            {
                prev_idx = i;
                break;
            }
        }

        if (prev_idx == -1)
        {
            return n <= 0;
        }

        for (int i = prev_idx; i < len && n > 0; i++)
        {
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i + 1 == len || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};
