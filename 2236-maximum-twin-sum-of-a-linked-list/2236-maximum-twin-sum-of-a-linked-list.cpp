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
    int pairSum(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<int> st;
        ListNode* slow = head;
        ListNode* fast = head;
        int maximum = INT_MIN;
        while(fast && fast->next){
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        while(slow){
            maximum = max(maximum, st.top() + slow->val);
            st.pop();
            slow = slow->next;
        }
        return maximum;
    }
};