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

    ListNode *returnPointofContact(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && slow && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return slow;
        }
        return NULL;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode *pointOfContact = returnPointofContact(head);
        while(head && pointOfContact){
            if(head == pointOfContact)
                return head;
            head = head->next;
            pointOfContact = pointOfContact->next;
        }
        return NULL;
    }
};