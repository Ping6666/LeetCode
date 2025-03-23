/*
Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/

#include <stddef.h>

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
    // Runtime: 28 ms (78.73 %), Memory: 71.6 MB (10.94 %).
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ansListNode = new ListNode(0), *headListNode;
        headListNode = ansListNode;
        int adder = 0;
        while (l1 || l2 || adder)
        {
            if (l1)
            {
                adder += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                adder += l2->val;
                l2 = l2->next;
            }
            ansListNode->next = new ListNode(adder % 10);
            ansListNode = ansListNode->next;
            adder /= 10;
        }
        return headListNode->next;
    }
};
