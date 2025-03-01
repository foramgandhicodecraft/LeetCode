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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL){
            return NULL;
        }
        ListNode* current;
        current = head;
        ListNode* temp;
        temp = head;
        while (current != NULL){
            current = current->next;
            if (current != NULL){
             if (temp->val != current->val){
                temp->next = current;
                temp = current;
             }
            }
        }
        if (temp-> next != NULL){
            temp->next = NULL;
        }
        return head;
    
    }
};