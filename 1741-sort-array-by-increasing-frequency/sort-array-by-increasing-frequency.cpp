class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int>m;
        int i = 0;

        for (int num:nums){
            m[num]++;
        }

        // map<int, int>m1;

        // for (auto key:m){
        //     m1[key.second] = key.first;
        // }

        // for (auto key:m1){
        //     cout<<key.second<<endl;
        //     int j = key.first;
        //     cout<<j<<endl;
        //     while (j--){
        //         nums[i] = key.second;
        //         i++;
        //     }
        // }

       // reverse(nums.begin(), nums.end());

       int min = INT_MAX;
       int number = 0;

       while (i < nums.size()){

       for (auto key:m){
        if (key.second < min) { 
            min = key.second;
            number = key.first;
        } else if (key.second == min) {
            if (number < key.first){
                number = key.first;
            }
        }
       }

       m.erase(number);
       while (i < nums.size() && min--){
        nums[i++] = number;
       }

       min = INT_MAX;

       }

        return nums;
    }
};