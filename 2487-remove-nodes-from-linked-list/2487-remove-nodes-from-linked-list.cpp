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
    ListNode* remove(ListNode* head){
        if(!head->next){
            return head;
        }
        head->next = remove(head->next);
        return (head->val < head->next->val) ? head->next : head;
    }
    
    ListNode* removeNodes(ListNode* head) {
        // using stack
        // stack<ListNode*> s;
        // s.push(head);
        // head = head->next;
        // while(head){
        //     while(!s.empty() && s.top()->val < head->val){
        //         s.top()->next = nullptr;
        //         s.pop();
        //     }
        //     if(!s.empty()){
        //         s.top()->next = head;
        //     }
        //     s.push(head);
        //     head = head->next;
        // }
        // while(!s.empty()){
        //     head = s.top();
        //     s.pop();
        // }
        // return head;
        
        // using recursion
        return remove(head);
    }
};