class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;  // Corrected from mid+1 to mid
            }

            // Check if the left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // Search in the left half
                } else {
                    left = mid + 1;   // Search in the right half
                }
            }
            // Otherwise, the right half must be sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // Search in the right half
                } else {
                    right = mid - 1; // Search in the left half
                }
            }
        }

        return -1;  // Target not found
    }
};
