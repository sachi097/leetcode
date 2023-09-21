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
        if(!head) return NULL;
        ListNode* curr = head;
        ListNode* headKeeper = head;
        ListNode* temp = head;
        int i=0;
        while(i < n-1){
            head = head->next;
            i++;
        }
        while(head->next){
            head = head->next;
            temp = curr;
            curr = curr->next;
        }
        if(curr != headKeeper &&& temp->next && temp->next->next){
            temp->next = temp->next->next;
            delete curr;
            return headKeeper;
        }
        if(!curr->next){
            temp->next = NULL;
        }
        if(curr == headKeeper && curr->next){
            headKeeper = curr->next;
        }
        else if(curr == headKeeper){
            headKeeper = NULL;
        }
        delete curr;
        return headKeeper;
    }
};