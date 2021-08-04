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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *h1 = headA;
        ListNode *h2 = headB;

        if (!h1 || !h2)
            return NULL;

        while (h1 != h2)
        {
            h1 = h1->next;
            h2 = h2->next;

            if (h1 == h2)
            {
                break;
            }

            if (!h1)
            {
                h1 = headB;
            }
            if (!h2)
            {
                h2 = headA;
            }
        }

        return h1;
    }
};