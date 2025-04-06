class Solution {
public:

    int first_element(vector<int>& nums, int target,int low,int high){
        int first = -1;
            while (low<=high){
                
                int mid = low + (high-low) / 2;
                if (nums[mid] > target){
                    high = mid-1;
                }
                else if (nums[mid] < target){
                    low = mid+1;
                }else{
                    first = mid;
                    high = mid-1;
                }
            }
        return first;
    }

    int last_element(vector<int>& nums, int target,int low,int high){
        int last = -1;
            while (low<=high){
                int mid = low + (high-low) / 2;
                if (nums[mid] > target){
                    high = mid-1;
                }
                else if (nums[mid] < target){
                    low = mid+1;
                }else{
                    last = mid;
                    low = mid+1;
                }
            }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int first = first_element(nums,target,low,high);
        int last = last_element(nums,target,low,high);

        vector<int>ans;
        ans.push_back(first);
        ans.push_back(last);

        return ans;


    }
};