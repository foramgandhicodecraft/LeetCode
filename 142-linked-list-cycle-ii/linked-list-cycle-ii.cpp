/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        int count = 0;
        ListNode* fast = head, *slow = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast){
              count++;
              break;
            }
        }
        if(count == 0)
          return NULL;
        fast = head;
        int pos = 0;
        while (fast != slow){
            fast = fast->next;
            slow = slow->next;
            pos++;
        }
        return fast;
    }
};