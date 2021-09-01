#include <iostream>
#include <cstring>

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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode();
        ListNode *curr = ans;

        int rem = 0;

        while (l1 || l2)
        {
            if (l1 and l2)
            {
                curr->next = new ListNode(l1->val + l2->val + rem);
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 and !l2)
            {
                curr->next = new ListNode(l1->val + rem);
                l1 = l1->next;
            }
            else if (!l1 and l2)
            {
                curr->next = new ListNode(l2->val + rem);
                l2 = l2->next;
            }

            if (curr->next->val > 9)
            {
                curr->next->val -= 10;
                rem = 1;
            }
            else
            {
                rem = 0;
            }

            curr = curr->next;
        }

        if (rem == 1)
        {
            curr->next = new ListNode(1);
        }

        return ans->next;
    }
};