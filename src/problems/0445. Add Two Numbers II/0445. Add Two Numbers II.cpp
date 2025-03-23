#include <stdio.h>

#include <algorithm> // max

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    // Runtime: 20 ms (Beats 99.01 %), Memory: 70.59 MB (Beats 99.52 %).

    // Solve the problem with constraint => "Follow up: Could you solve it without reversing the input lists?"

private:
    int getListNodeSize(ListNode *l)
    {
        int n = 0;
        ListNode *l_next;

        while (l != nullptr)
        {
            l = l->next;
            n += 1;
        }

        return n;
    }

    void agjustListNodeSize(ListNode **l, int n, int adj_n)
    {
        int diff = adj_n - n;

        for (int i = 0; i < diff; i++)
        {
            ListNode *l_tmp = new ListNode();
            l_tmp->next = *l;
            *l = l_tmp;
        }
    }

    void agjustWorker(ListNode **l1, ListNode **l2)
    {
        int l1_n, l2_n, max_n;

        l1_n = getListNodeSize(*l1);
        l2_n = getListNodeSize(*l2);
        max_n = max(l1_n, l2_n) + 1;

        agjustListNodeSize(l1, l1_n, max_n);
        agjustListNodeSize(l2, l2_n, max_n);
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // l1 = l1 + l2

        int curr_sum = 0;
        int l1_val, l2_val, curr_remain, curr_carry;

        ListNode *l1_ptr, *l2_ptr, *l_carry;

        agjustWorker(&l1, &l2);

        l1_ptr = l1;
        l2_ptr = l2;
        l_carry = l1;

        while (l1_ptr != nullptr && l2_ptr != nullptr)
        {
            l1_val = l1_ptr->val;
            l2_val = l2_ptr->val;

            curr_sum = l1_val + l2_val;
            curr_remain = curr_sum % 10;
            curr_carry = (curr_sum - curr_remain) / 10;

            l1_ptr->val = curr_remain;

            if (curr_carry != 0)
            {
                while (l_carry != l1_ptr)
                {
                    l_carry->val = (l_carry->val + 1) % 10;
                    l_carry = l_carry->next;
                }
            }
            else if (curr_remain != 9)
            {
                // not having potential carry
                l_carry = l1_ptr;
            }

            // next
            l1_ptr = l1_ptr->next;
            l2_ptr = l2_ptr->next;
        }

        // remove front 0

        while (l1 != nullptr && l1->val == 0 && l1->next != nullptr)
        {
            l1 = l1->next;
        }

        return l1;
    }
};

void printNumber(ListNode *l)
{
    ListNode *tmp = l;

    while (tmp != nullptr)
    {
        printf("%d", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");

    return;
}

int main()
{
    ListNode *l1_1, *l1_2, *l1_3, *l1_4;
    ListNode *l2_1, *l2_2, *l2_3;

    Solution s;

    l1_1 = new ListNode(7);
    l1_2 = new ListNode(2);
    l1_3 = new ListNode(4);
    l1_4 = new ListNode(3);
    l1_1->next = l1_2;
    l1_2->next = l1_3;
    l1_3->next = l1_4;

    l2_1 = new ListNode(5);
    l2_2 = new ListNode(6);
    l2_3 = new ListNode(4);
    l2_1->next = l2_2;
    l2_2->next = l2_3;

    s = Solution();
    printNumber(l1_1);
    printNumber(l2_1);
    l1_1 = s.addTwoNumbers(l1_1, l2_1);
    printNumber(l1_1);

    l1_1 = new ListNode(9);
    l1_2 = new ListNode(9);
    l1_3 = new ListNode(9);
    l1_4 = new ListNode(9);
    l1_1->next = l1_2;
    l1_2->next = l1_3;
    l1_3->next = l1_4;

    l2_1 = new ListNode(1);

    s = Solution();
    printNumber(l1_1);
    printNumber(l2_1);
    l1_1 = s.addTwoNumbers(l1_1, l2_1);
    printNumber(l1_1);

    return 0;
}
