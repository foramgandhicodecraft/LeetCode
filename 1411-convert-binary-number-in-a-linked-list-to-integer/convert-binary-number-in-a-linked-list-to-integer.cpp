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
    int getDecimalValue(ListNode* head) {
        vector<int>arr(30);

        ListNode* p = head;
        while (p->next){
            arr.push_back(p->val);
            p = p->next;
        }
        arr.push_back(p->val);

        int index = 0;
        int i = arr.size()-1;
        int ans = 0;

        while (i >= 0){
            ans += arr[i] * pow(2, index);
            index++;
            i--;
        }

        return ans;


    }
};