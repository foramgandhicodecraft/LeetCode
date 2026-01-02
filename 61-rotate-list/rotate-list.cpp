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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        ListNode* tail = head;
        int length = 1;

        while (tail->next != nullptr){
            length++;
            tail = tail->next;
        }

        if (k%length == 0) return head;

        k = k%length;
        

        ListNode* p = head;
        int iterations = length - k -1;
        tail->next = head;

        while (iterations--){
            p = p->next;
        }
        head = p->next;
        p->next = NULL;

        return head;
    }
};