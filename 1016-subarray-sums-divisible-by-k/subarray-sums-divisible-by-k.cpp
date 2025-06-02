class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //vector<int>temp;
        //int count = 0;
        
        // for (int i = 0; i < nums.size(); i++){
        //     // temp.push_back(nums[i]);
        //     int sum = nums[i];
        //     if(sum%k==0) count++;
        //     for (int j = i+1; j <nums.size(); j++){
        //         sum += nums[j];
        //         if (sum % k == 0)
        //          count++;
        //     }
        // }
      
        unordered_map<int,int> ans;
        int sum=0;
        int count=0;
        ans[0] = 1;
        for(int i=0;i<nums.size();i++){
           
            sum+=nums[i];
            ans[(sum % k + k) % k]++;
            
        }
        
        for(auto t:ans){
          int freq = t.second;
          count += (freq * (freq - 1)) / 2;
        }
        return count;
    }
    
};