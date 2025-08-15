class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;

        for (auto num:nums){
            m[num]++;
        }

        priority_queue<pair<int,int>>max_heap;

        for (auto [num, frequency]:m){
            max_heap.push({frequency,num});
        }

        vector<int>result;

        for (int i = 0; i < k; i++){
            int j = max_heap.top().second;
            max_heap.pop();
            result.push_back(j);
        }

        return result;
    }
};