class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        // i am gonna get 2 sorted arrays or one sorted array
        // i need to find position where nums[i] > nums[i+1]
        // how do i adjust the high and low pointers of binary search? 
        //L <= R, FOR THE EXACT ELEMENT
        // L < R, FOR MIN, MAX, LAST OCC., FIRST OCC.
        int l = 0;
        int h = n-1;
        // bool found = false;
        // int ans;

        // while (l < h){
        //     int mid = l + (h-l)/2;
            
        //     if (nums[mid] > nums[mid+1]){
        //         found = true;
        //         ans = nums[mid+1];
        //     }
        // }

        // if (!found){
        //     return nums[0];
        // }

        // return ans;

        while (l < h){
            int mid = l + (h-l)/2;
            if (nums[mid] > nums[h]){
                l = mid+1;
            }
            else {
                h = mid;
            }
        }

        return nums[h];
    }
};