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
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        if(!ptr1 || !ptr2) return NULL;
        while(ptr1 != ptr2){
            if(!ptr1){
                ptr1 = headB;
            }
            if(!ptr2){
                ptr2 = headA;
            }
            if(ptr1 == ptr2){
                return ptr1;
            }
            else{
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
        return ptr1;
    }
};