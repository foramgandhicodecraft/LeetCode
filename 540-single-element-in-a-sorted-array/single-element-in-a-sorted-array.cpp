class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int ans;

        while (l <= r){
            int mid = l + (r - l) / 2;
            if ((mid-1 < 0 || nums[mid] != nums[mid-1]) && (mid+1 > nums.size()-1 || nums[mid] != nums[mid+1])){
                ans = nums[mid];
                break;
            }
            
            int left_length;
            if (mid > 0 && nums[mid-1] == nums[mid]){
                left_length = mid-1;
            }else{
                left_length = mid;
            }

            if (left_length % 2){ //left length is odd
               r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};