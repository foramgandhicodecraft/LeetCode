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
        ListNode dummy;
        dummy.next = head;
        ListNode* first = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i <= n; i++){
            first = first->next;
        }

        while (first != nullptr){
            first = first->next;
            slow = slow->next;
        }

        ListNode* deleteNode = slow->next;
        slow->next = deleteNode->next;
        deleteNode->next = nullptr;
        delete deleteNode;

        return dummy.next;
    }
};