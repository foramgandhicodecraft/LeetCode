class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n = nums2.size();
        int m = nums1.size();
        vector<int>nge(n, -1);
        vector<int>ans(m);

        for (int i = n-1; i >= 0; i--){
            while (st.size() != 0 && st.top() <= nums2[i]){
                st.pop();
            }
            if (st.size() != 0){
                nge[i] = st.top();
            }
            st.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++){
            for (int j = 0; j < n; j++){
                if (nums1[i] == nums2[j]){
                    ans[i] = nge[j];
                }
            }
        }

        return ans;
    }
};