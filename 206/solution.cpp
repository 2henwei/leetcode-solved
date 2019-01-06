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
    /* Iterative Version */
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    /* Recursive Version */
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* rhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return rhead;
    }
};
