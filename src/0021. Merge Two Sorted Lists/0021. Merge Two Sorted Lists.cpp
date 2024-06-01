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
    // Runtime: 4 ms (94.53 %), Memory: 14.8 MB (82.26 %).
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ansheader = new ListNode(0), *tmpnode;
        tmpnode = ansheader;
        if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                tmpnode->next = list1;
                list1 = list1->next;
            }
            else
            {
                tmpnode->next = list2;
                list2 = list2->next;
            }
            tmpnode = tmpnode->next;
        }
        if (list1 == NULL)
            tmpnode->next = list2;
        else if (list2 == NULL)
            tmpnode->next = list1;
        return ansheader->next;
    }
};
