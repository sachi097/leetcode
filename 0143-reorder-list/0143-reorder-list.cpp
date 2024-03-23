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
    ListNode* reverse(ListNode* head){
        ListNode *prev = nullptr, *curr = head;
        while(curr){
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head, *slowTemp, *fastTemp;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        slowTemp = slow;
        slow = reverse(slow->next);
        slowTemp->next = nullptr;
        slowTemp = slow;
        fast = head;
        fastTemp = fast;
        while(slow){
            slow = slow->next;
            fast = fast->next;
            fastTemp->next = slowTemp;
            slowTemp->next = fast;
            slowTemp = slow;
            fastTemp = fast;
        }
    }
};