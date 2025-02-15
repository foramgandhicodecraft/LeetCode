class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>stack;
        int nge[nums2.size()];
        vector<int>ans;

        for (int i = nums2.size()-1; i >= 0; i--){
            
            while (stack.size() != 0 && stack[stack.size()-1] <= nums2[i]){
                stack.pop_back();
            }
            if (stack.size() != 0){
                nge[i] = stack[stack.size()-1];
                stack.push_back(nums2[i]);
            }
            else{
                nge[i] = -1;
                stack.push_back(nums2[i]);
            }
        }
        for (int i =0; i < nums1.size(); i++){
            for (int j = 0; j < nums2.size(); j++){
                if (nums1[i] == nums2[j]){
                    ans.push_back(nge[j]);
                }
            }
        }

        return ans;
    }
};