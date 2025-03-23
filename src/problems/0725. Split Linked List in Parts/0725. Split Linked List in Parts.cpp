#include <vector>
using std::vector;

// Runtime: 3 ms (Beats 89.05 %), Memory: 13.76 MB (Beats 81.80 %).

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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int c = 0;

        ListNode *tmp_ptr = head;
        while (!(!tmp_ptr))
        {
            c++;
            tmp_ptr = tmp_ptr->next;
        }

        int r = c % k;
        c /= k;
        // printf("%d %d\n", r, c);

        vector<ListNode *> ans(k, nullptr);

        tmp_ptr = head;
        for (int i = 0; i < k && !(!tmp_ptr); i++)
        {
            ans[i] = tmp_ptr;

            for (int j = ((r > i) ? -1 : 0); j < c - 1; j++)
            {
                // printf("%d %d %d\n", j, c, tmp_ptr->val);

                tmp_ptr = tmp_ptr->next;
            }
            // printf("\n");

            head = tmp_ptr->next;

            tmp_ptr->next = nullptr;
            tmp_ptr = head;
        }

        return ans;
    }
};
