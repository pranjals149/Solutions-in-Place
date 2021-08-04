/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;

        ListNode *first = head;
        ListNode *second = head;

        while (first != NULL and first->next != NULL)
        {
            first = first->next->next;
            second = second->next;

            if (first == second)
                return true;
        }

        return false;
    }
};