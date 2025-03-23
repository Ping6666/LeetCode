#include <stdlib.h>

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
    // Runtime: 367 ms (Beats 98.97 %), Memory: 256.48 MB (Beats 96.69 %).
    // in-place

public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *prev_zero = head;
        ListNode *curr = head->next;

        int val = 0;
        while (curr != nullptr)
        {
            if (curr->val == 0)
            {
                curr->val = val;
                val = 0;

                prev_zero->next = curr;
                prev_zero = prev_zero->next;
            }
            else
            {
                val += curr->val;
            }

            curr = curr->next;
        }

        return head->next;
    }
};

/*
class Solution
{
    // Runtime: 452 ms (Beats 46.50 %), Memory: 277.94 MB (Beats 50.49 %).
    // not-in-place

public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *new_head = nullptr, *new_tail = nullptr;
        ListNode *temp = head->next;

        int val = 0;
        while (temp != nullptr)
        {
            if (temp->val == 0)
            {
                if (new_head == nullptr)
                {
                    new_head = new ListNode(val);
                    new_tail = new_head;
                }
                else
                {
                    new_tail->next = new ListNode(val);
                    new_tail = new_tail->next;
                }

                val = 0;
            }
            else
            {
                val += temp->val;
            }

            temp = temp->next;
        }

        return new_head;
    }
};
*/
