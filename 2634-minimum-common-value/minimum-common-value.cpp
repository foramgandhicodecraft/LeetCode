class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());
        int m = nums1.size();
        // int n = nums2.size();

        // int i = 0;
        // int j = 0;

        // for (int i = 0; i < m; i++){
        //     for (int j = 0; j < n; j++){
        //         if (nums1[i] == nums2[j]){
        //             return nums1[i];
        //         }
        //     }
        // }

        // return -1;

        //set<int>s1(nums1.begin(), nums1.end());
        set<int>s2(nums2.begin(), nums2.end());

        for (int i = 0; i < m; i++){
            if (s2.find(nums1[i]) != s2.end()){
                return nums1[i];
            }
        }

        return -1;



        
    }
};