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
        unordered_map<int,int> hashMap;
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 0, maximum = INT_MIN;
        while(fast && fast->next){
            hashMap[count++] = slow->val;
            slow = slow->next;
            fast = fast->next->next;
        }
        count--;
        while(slow){
            maximum = max(maximum, hashMap[count--] + slow->val);
            slow = slow->next;
        }
        return maximum;
    }
};