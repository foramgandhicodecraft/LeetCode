class Node {
    public:
    Node* link[2];
    void put(int num, Node* node){
        link[num] = node;
    }
    Node* get(int num){
        return link[num];
    }
    bool containsKey(int num){
        return link[num] != NULL;
    }
};

// indexing in numbers goes from right to left
class trie{
    private:
    Node* root;
    public:
     trie(){
        root = new Node();
     }
    
    public:
     void insert(int num){
        Node* node = root;
        for (int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)){
                node->put(bit, new Node());
            }

            node = node->get(bit);

        }
     }

    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if (node->containsKey(1-bit)) {
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            } else {

                node = node->get(bit);
            }
        }
        return maxNum;
    }


};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        int ans = INT_MIN;
        int current;

        trie Trie;

        for (int i = 0; i < nums.size(); i++){
            Trie.insert(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++){
            current = Trie.getMax(nums[i]);
            ans = max(ans,current);
        }

        return ans;
    }
};