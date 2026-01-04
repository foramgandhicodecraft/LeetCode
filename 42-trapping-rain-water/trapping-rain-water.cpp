class Solution {
public:
    int trap(vector<int>& height) {
        
        // finding nge from right and left fro all elements
        // int water = 0;
    
        // //0 ka alag se left
        // int l = 1;
        // bool zero = false;
        // while (l < height.size()){
        //     if (height[l] > height[0]){
        //         zero = true;
        //     }
        // }

        // if (zero){
        //     water += height[0];
        // }

        // int j = 1;
        // while (j < height.size()-1){
        //     vector<int>stack1;
        //     vector<int>stack2;

        //     stack1.push_back(height[j]);
        //     stack2.push_back(height[j]);

        //     // 0 to current element
        //     for (int k = 0; k < j; k++){
        //         if ((height[k] > stack1.back() || stack1.empty()) && height[k] > height[j]){
        //             stack1.push_back(height[k]);
        //         }
        //     }
        //     // current element to size-1
        //     for (int k = j; k < height.size(); k++){
        //         if (height[k] > stack2.back() || stack2.empty()){
        //             stack2.push_back(height[k]);
        //         }
        //     }

        //     if (!stack1.empty()){
        //         water += height[j];
        //     }

        //     if (!stack2.empty()){
        //         water += height[j];
        //     }
        // }

        // return water;

        int water = 0;
        // adjacent
        // int i = 0;
        // int j = 1;
        // while (j < height.size()){
        //     if (height[i] != 0 && height[j] != 0){
        //         water += min(height[i], height[j]);
        //     }
        // }

        // int j = 1;
        // while (j < height.size()-1){
        //     int max_right = 0;
        //     int max_left = 0;

        //     // 0 to current element
        //     for (int k = 0; k < j; k++){
        //         if (height[k] > max_left){
        //             max_left = height[k];
        //         }
        //     }
        //     // current element to size-1
        //     for (int k = j; k < height.size(); k++){
        //         if (height[k] > max_right){
        //             max_right = height[k];
        //         }
        //     }

        //     if (min(max_left, max_right) - height[j] > 0){
        //         water += min(max_left, max_right) - height[j];
        //     }
        //     j++;

        // }

        // return water;

        vector<int>left_max(height.size());
        vector<int>right_max(height.size());
        int lmaxi = height[0];
        int rmaxi = height[height.size()-1];

        for (int i = 0; i < height.size(); i++){
            lmaxi = max(height[i], lmaxi);
            left_max[i] = lmaxi;
        }

        for (int i = height.size()-1; i >= 0; i--){
            rmaxi = max(height[i], rmaxi);
            right_max[i] = rmaxi;
        }

        for (int i = 0; i < height.size(); i++){
            if (min(left_max[i], right_max[i]) - height[i] > 0){
                water += min(left_max[i], right_max[i]) - height[i];
            }
        }

        return water;

    }
};