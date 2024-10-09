#include <vector>
#include <unordered_set>
using std::vector, std::unordered_set;

// Runtime: 396 ms (Beats 95.15 %), Memory: 258.36 MB (Beats 91.24 %).

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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> table;
        for (const auto &n : nums)
        {
            table.insert(n);
        }

        ListNode *curr_ptr = head;
        ListNode *prev_ptr = nullptr;

        while (!(!curr_ptr))
        {
            if (table.find(curr_ptr->val) != table.end())
            {
                // hit
                if (head == curr_ptr)
                {
                    head = curr_ptr->next;
                }
                else if (!(!prev_ptr))
                {
                    prev_ptr->next = curr_ptr->next;
                }
            }
            else
            {
                prev_ptr = curr_ptr;
            }
            curr_ptr = curr_ptr->next;
        }

        return head;
    }
};
