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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> hash;
        int prefixSum = 0;
        ListNode *temp, *deleteNode, *curr = head;
        while(curr){
            prefixSum += curr->val;
            if(prefixSum == 0){
                hash.clear();
                head = curr->next;
            }
            else{
              auto it = hash.find(prefixSum);
                if(it != hash.end()){
                    temp = it->second->next;
                    it->second->next = curr->next;
                    int tempSum = prefixSum;
                    while(temp != curr){
                        deleteNode = temp;
                        tempSum += temp->val;
                        temp = temp->next;
                        hash.erase(tempSum);
                        delete deleteNode;
                    }
                }
                else{
                    hash[prefixSum] = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};
