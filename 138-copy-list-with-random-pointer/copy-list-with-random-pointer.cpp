/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if (head == nullptr){
            return nullptr;
        }
        
        map<Node*, Node*>old_random;

        Node* ptr = head;
        while (ptr != nullptr){
            old_random[ptr] = ptr->random;
            ptr = ptr->next;
        }

        ptr = head;
        Node* newHead = new Node(ptr->val);
        Node* prev = newHead;
        map<Node*, Node*>old_new;
        old_new[ptr] = prev;
        ptr = ptr->next;

        while (ptr){
            Node* newNode = new Node(ptr->val);
            prev->next = newNode;
            prev = newNode;
            old_new[ptr] = prev; 
            ptr = ptr->next;
        }

        ptr = head;
        Node* newRandom = newHead;

        while (ptr){
            if (old_random[ptr] == nullptr){
                newRandom->random = nullptr;
            }
            else {
                newRandom->random = old_new[old_random[ptr]];
            }

            newRandom = newRandom->next;
            ptr = ptr->next;
        }

        return newHead;

    }
};