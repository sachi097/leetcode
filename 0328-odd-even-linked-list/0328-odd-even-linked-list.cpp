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
    ListNode* oddEvenList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(!head || !head->next) return head;
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        ListNode* oddPointer = head;
        ListNode* evenPointer = head->next;
        while(evenPointer && evenPointer->next){
            //odd increment should come before even else program will go into runtime error
            oddPointer->next = oddPointer->next->next;
            evenPointer->next = evenPointer->next->next;
            evenPointer = evenPointer->next;
            oddPointer = oddPointer->next;
        }
        oddPointer->next = evenHead;
        return head;
    }
};