class NumArray {
public:
    vector<int>arr;
    NumArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            arr.push_back(nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        int sum;
        for (int i = left; i <= right; i++){
            sum += arr[i];
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */