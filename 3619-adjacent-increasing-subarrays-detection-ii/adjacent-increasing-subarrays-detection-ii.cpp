class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        
        int n = nums.size();

        // use sliding window and store the starting and ending index of each increasing subarray in an array
        // check for adjacent and increasing

        int l = 0;
        vector<int>ind;
        int k = 0;
        int r;

        // if (n == 2){
        //     if (nums[1] > nums[0]){
        //         return 1;
        //     }
        // }

        for (r = 1; r < n; r++) {
            if (nums[r] <= nums[r-1]){
                ind.push_back(l);
                ind.push_back(r-1);
                l = r;
            }
        }

        int flag = 0;
        for (int i = l; i < r-1; i++){
            if (nums[i] > nums[i+1]){
                flag = 1;
                break;
            }
        }
        if (!flag){
            ind.push_back(l);
            ind.push_back(r-1);
        }

        // for (int i = 0; i < ind.size(); i++){
        //     cout<<ind[i]<<endl;
        // }

        l = 0;
        r = 1;
        int m = ind.size();

        if (m == 0) return 0;

        if (m == 2){
            l = 0;
            r = 1;
            return (ind[r]-ind[l]+1)/2;
        }

        while (r < m-2){

            int l1 = ind[r] - ind[r-1] + 1;
            int l2 = ind[r+2] - ind[r+1] + 1;
            k = max(k, l1/2);
            k = max(k, l2/2);

            if (ind[r]+1 == ind[r+1]){
                if (l2 > l1){
                    k = max(k, l1);
                }
                else if (l2 < l1){
                    k = max(k, l2);
                }
                else if (l1 == l2){
                    k = max(k, l1);
                }

            }
            r += 2;
        }

        return k;


        
    }
};