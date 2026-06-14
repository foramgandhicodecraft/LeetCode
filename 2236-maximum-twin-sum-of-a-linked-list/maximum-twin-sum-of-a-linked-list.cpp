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
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        int ans;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = head;

        ListNode* current = slow;
        ListNode* next = slow;
        ListNode* prev = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        while (prev) {
            ans = max(ans, fast->val+prev->val);
            prev = prev->next;
            fast = fast->next;
        }

        return ans;
    }
};