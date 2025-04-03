class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>q;
        for (int num:nums){
            q.push(num);
        }

        for (int i = 0; i < k-1; i++){ //remove k-1 to get the k-th largest
            q.pop();
        }

        return q.top();
    }
};