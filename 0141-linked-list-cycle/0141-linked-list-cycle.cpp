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
        if(!head)  return false;
        ListNode* slow = head;
        while(head && slow && head->next){
            head = head->next->next;
            slow = slow->next;
            if(head == slow) return true;
        }
        return false;
    }
};