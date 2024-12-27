class Solution {
public:
    int count = 0; // Variable to keep track of reverse pairs

    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp(high - low + 1);
        int i = low, j = mid + 1, k = 0;

        // Merging two sorted halves
        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        // Copy remaining elements from left half
        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        // Copy remaining elements from right half
        while (j <= high) {
            temp[k++] = nums[j++];
        }

        // Copy back the sorted elements into the original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    void countPairs(vector<int>& nums, int low, int mid, int high) {
        int right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && nums[i] > 2LL * nums[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        countPairs(nums, low, mid, high); // Count reverse pairs
        merge(nums, low, mid, high);     // Merge the two halves
    }
};
