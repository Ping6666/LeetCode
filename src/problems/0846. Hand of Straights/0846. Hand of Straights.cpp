#include <vector>
#include <algorithm>
#include <iostream>
using std::vector, std::sort;

void printf_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

class Solution
{
    // Runtime: 37 ms (Beats 95.48 %), Memory: 23.00 MB (Beats 99.86 %).
    // in-place, same question as q.1296

public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        // magic
        std::ios_base::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);

        int l = hand.size();

        if ((groupSize > l) || ((l % groupSize) != 0))
        {
            return false;
        }
        else if (groupSize == 1)
        {
            return true;
        }

        sort(hand.begin(), hand.end());

        int count, curr_value;
        while (l > 0)
        {
            count = 1;
            curr_value = hand[0];

            // remove item
            hand.erase(hand.begin() + 0);
            l--;

            for (int idx = 0; idx < l && count < groupSize; idx++)
            {
                // init idx = 0 since the front has been removed

                if (curr_value + 1 == hand[idx])
                {
                    // consecutive
                    curr_value++;
                    count++;

                    // remove item
                    hand.erase(hand.begin() + idx);
                    l--;
                    idx--;
                }
            }

            if (count != groupSize)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<int> hand;
    int groupSize;
    bool ans;

    hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    groupSize = 3;
    ans = Solution().isNStraightHand(hand, groupSize);

    printf("%d\n", ans);

    return 0;
}
