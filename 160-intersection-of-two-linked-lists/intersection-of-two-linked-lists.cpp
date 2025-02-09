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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *start = headB;
        int count = 0;

        while (headA != nullptr){
            while (start != nullptr){
                if (headA == start){
                    return start;
                }
                else{
                    start = start->next;
                    count = 0;
                }
            }

            headA = headA->next;
            start = headB;
        }
        return NULL;
    }
};