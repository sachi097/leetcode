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

    ListNode* reverse(ListNode* temp, ListNode* head){
        if(!temp->next){
            head = temp;
            return head;
        };
        head = reverse(temp->next, head);
        temp->next->next = temp;
        temp->next = NULL;
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(!head) return head;
        return reverse(head, head);
    }
};