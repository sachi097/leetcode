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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp1 = list1, *temp2 = list2, *curr;
        while(temp2->next){
            temp2 = temp2->next;
        }
        int i = 1;
        while(i < a && temp1){
            temp1 = temp1->next;
            i++;
        }
        curr = temp1->next;
        temp1->next = list2;
        while(i < b && curr){
            auto deleteNode = curr;
            curr = curr->next;
            delete deleteNode;
            i++;
        }
        temp2->next = curr->next;
        delete curr;
        return list1;
    }
};