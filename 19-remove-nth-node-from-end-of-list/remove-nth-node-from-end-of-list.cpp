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
        int size = 0;
        ListNode* tail = head;
        ListNode dummy;
        dummy.next = head;


        while (tail != nullptr){
            size++;
            tail = tail->next;
        }

        ListNode* current = &dummy;

        int iterations = size - n;

        while (iterations--){
            current = current->next;
        }

        ListNode* deleteNode = current->next;
        current->next = deleteNode->next;
        delete deleteNode;

       return dummy.next; 
    }
};