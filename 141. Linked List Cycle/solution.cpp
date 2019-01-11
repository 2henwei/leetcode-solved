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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        ListNode *turtle = head;
        ListNode *rabbit = head->next;

        while (turtle && rabbit) {
            if (turtle == rabbit) return true;
            if (!rabbit->next) return false;
            turtle = turtle->next;
            rabbit = rabbit->next->next;
        }
        return false;
    }
};
