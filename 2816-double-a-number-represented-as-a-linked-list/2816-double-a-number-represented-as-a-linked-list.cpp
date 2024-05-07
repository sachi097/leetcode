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
class Solution {
public:
    void doubleValue(ListNode* head, int &carry){
        if(!head){
            return;
        }
        doubleValue(head->next, carry);
        int newValue = (head->val * 2) + carry;
        head->val = newValue % 10;
        carry = newValue / 10;
    }
    
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        doubleValue(head, carry);
        if(carry){
            head = new ListNode(carry, head);
        }
        return head;
    }
};