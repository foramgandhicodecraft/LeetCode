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
    ListNode* reverseLL(ListNode* temp){
        ListNode* current = temp;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        temp = prev;
        return temp;
    }

    ListNode* findkthnode(ListNode* temp, int k){
        k -= 1;
        while(k-- && temp != nullptr){
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp != nullptr){
            ListNode* kThNode = findkthnode(temp, k);

            if (kThNode == nullptr){
                if (prevLast){
                    prevLast->next = temp;
                }
                break;
            }

            ListNode* nextNode = kThNode->next;
            kThNode->next = nullptr;

            ListNode* newHead = reverseLL(temp);

            if (temp == head){
                head = kThNode;
                prevLast = temp;
            }
            else{
                prevLast->next = kThNode;
            }

            
            
            prevLast = temp;
            temp = nextNode;

        }

        return head;
    }
};