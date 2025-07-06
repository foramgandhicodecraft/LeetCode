class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    map<int, int>m;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        for (int num:nums2){
            m[num]++;
        }
    }
    
    void add(int index, int val) {
        if (index >= 0 && index < nums2.size()){
            m[nums2[index]]--;
            nums2[index] += val;
            m[nums2[index]]++;
        }
        
    }
    
    int count(int tot) {
        
        int ans = 0;
        for (int num:nums1){
            int counter = tot - num;
            // ans += std::count(nums2.begin(), nums2.end(), counter);
            if (counter >= 0){
                if (m.find(counter) != m.end()){
                  ans += m[counter];
                }
            }
            
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */