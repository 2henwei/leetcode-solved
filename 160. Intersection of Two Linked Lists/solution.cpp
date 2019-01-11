/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        size_t lenA = 0, lenB = 0;
        ListNode *head;

        head = headA;
        while (head) {
            ++lenA;
            head = head->next;
        }

        head = headB;
        while (head) {
            ++lenB;
            head = head->next;
        }

        while (lenA > lenB) {
            headA = headA->next;
            --lenA;
        }

        while (lenB > lenA) {
            headB = headB->next;
            --lenB;
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};
