#include <numeric>
using std::gcd;

// Runtime: 31 ms (Beats 91.70 %), Memory: 35.37 MB (Beats 95.59 %).

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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (!head->next)
        {
            return head;
        }

        ListNode *prev_ptr = nullptr, *curr_ptr = nullptr;
        prev_ptr = head;
        curr_ptr = head->next;

        while (!(!curr_ptr))
        {
            prev_ptr->next = new ListNode(gcd(prev_ptr->val, curr_ptr->val), curr_ptr);

            prev_ptr = curr_ptr;
            curr_ptr = curr_ptr->next;
        }

        return head;
    }
};
