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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head;
        int i = 0;
        for(auto i=0; i<n; i++){
            fast = fast->next;
        }
        if(!fast){
            auto delNode = head;
            head = head->next;
            delete delNode;
            return head;
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        auto delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};