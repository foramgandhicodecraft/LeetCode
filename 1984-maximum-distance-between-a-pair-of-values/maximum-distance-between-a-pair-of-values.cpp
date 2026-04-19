class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0; 
        int j = 0;
        int n = nums1.size();
        int distance = 0;

        while (i < n){
            int low = i+1;
            int high = nums2.size()-1;
            int target = nums1[i];
            while (low <= high){
                int mid = low + (high - low)/2;
                if (nums2[mid] > target){
                    low = mid+1;
                    distance = max(distance, mid-i);
                }
                else if (nums2[mid] < target){
                    high = mid-1;
                }
                else {
                    distance = max(distance, mid-i);
                    low = mid + 1;
                }
            }

            i++;
        }

        return distance;
    }
};