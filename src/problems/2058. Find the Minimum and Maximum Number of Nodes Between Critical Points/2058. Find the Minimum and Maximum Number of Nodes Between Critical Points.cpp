#include <vector>
using std::vector;

// Runtime: 161 ms (Beats 74.98 %), Memory: 115.63 MB (Beats 95.45 %).

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        int min_dist = -1, max_dist = -1;

        int j = 0;
        int first_critical = -1, last_critical = -1;

        int i = 0;
        int val1 = -1, val2 = -1;

        while (head != nullptr)
        {
            if (i == 0)
            {
                val2 = head->val;
            }
            else if (i == 1)
            {
                val1 = head->val;
            }
            else
            {
                if ((val1 > val2 && val1 > head->val) || (val1 < val2 && val1 < head->val))
                {
                    // found critical point
                    if (j == 0)
                    {
                        first_critical = i;
                        last_critical = i;
                    }
                    else
                    {
                        if (min_dist == -1 || (i - last_critical) < min_dist)
                        {
                            min_dist = i - last_critical;
                        }

                        max_dist = i - first_critical;
                        last_critical = i;
                    }

                    j++;
                }

                val2 = val1;
                val1 = head->val;
            }

            head = head->next;
            i++;
        }

        return {min_dist, max_dist};
    }
};
