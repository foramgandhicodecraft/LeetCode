class Solution {
public:
    int count = 0;

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return count;
    }

    void merge(vector<int>& nums, int low, int mid, int high){
        int i = low; int j = mid+1;
        int k = 0;
        int arr[high-low+1];

        while (i <= mid && j <= high){
            if (nums[i] < nums[j]){
                arr[k++] = nums[i++];
            }
            else{
                arr[k++] = nums[j++];
            }
        }

        while (i <= mid){
            arr[k++] = nums[i++];
        }
        while (j <= high){
            arr[k++] = nums[j++];
        }
        k = 0;

        for (int i = low; i <= high; i++){
            nums[i] = arr[k++];
        }
    }

    void countPairs(vector<int>& nums, int low, int mid, int high){
        int right = mid+1;
        for (int i = low; i <= mid; i++){
            while (right <= high && nums[i] > 2LL*nums[right]){
                right++;
            }
            count += right-(mid+1);
        }

    }

    void mergeSort(vector<int>& nums, int low, int high){
        if (low >= high) return;

        int mid = low + (high - low)/2;
        
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);
    }
};