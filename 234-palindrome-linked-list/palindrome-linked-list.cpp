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
        vector<int>check;
        ListNode* tail = head;

        while (tail != nullptr) {
            check.push_back(tail->val);
            tail = tail->next;
        }

        vector<int>check2(check);
        reverse(check.begin(), check.end());
        if (check == check2){
            return true;
        }

        return false;
    }
};