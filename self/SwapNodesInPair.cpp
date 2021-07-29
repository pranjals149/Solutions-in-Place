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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *curr = head, *prev = NULL, *next1 = NULL, *next2 = NULL;

        while (curr and curr->next)
        {
            next1 = curr->next;

            if (prev == NULL)
            {
                head = next1;
            }
            else
            {
                prev->next = next1;
            }

            next2 = next1->next;
            next1->next = curr;
            curr->next = next2;
            prev = curr;
            curr = next2;
        }

        return head;
    }
};