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
    bool isPalindrome(ListNode* head) {
        //ARRAY SOLUTION
        // ListNode* p = head;
        // vector<int>v;
        // while (p && p->next){
        //     v.push_back(p->val);
        // }
        
        // int l = v[0];
        // int r = v.size()-1;
        // while (l <= r){
        //     if (v[l] != v[r])
        //       return false;
        // }

        // return true;

        //O(1) SPACE
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* curr = slow;
        ListNode* prev = NULL;
        ListNode* nextNode;
        while (curr){
           nextNode = curr->next;
           curr->next = prev;
           prev = curr;
           curr = nextNode;
        }
        
        ListNode* p = head;
        ListNode* q = prev;
        while (q){
            if (q->val != p->val)
              return false;
            else{
                p = p->next;
                q = q->next;
            }
        }

        return true;
    }
};