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
        //O(K*N) APPROACH
        // if (head == NULL)
        //   return NULL;
        
        // vector<int>v;
        // ListNode* p =  head;
        // while (p != NULL){
        //     v.push_back(p->val);
        //     p = p->next;
        // }
    
        // while (k){
        //     int temp = v[v.size()-1];
        //     for (int i = v.size()-1; i > 0; i--){
        //         v[i] = v[i-1];
        //     }
        //     v[0] = temp;
        //     k--;
        // }
        // int i = 0;
        // p = head;
        // while (p != NULL){
        //     p->val = v[i];
        //     p = p->next;
        //     i++;
        // }
        // return head;

        if (head == NULL)
          return NULL;

        ListNode* tail = head;
        int length = 1;
        while (tail->next){
            length++;
            tail = tail->next;
        }
        k = k % length; //only do the necessary rotations, in multiples of length rotations not needed
        tail->next = head;
        int iterations = length - k - 1;
        ListNode* p = head;
        while (iterations--){
            p = p->next;
        }
        head = p->next;

        p->next = NULL; //watch striver 12 min video to understand

        return head;
    }
};