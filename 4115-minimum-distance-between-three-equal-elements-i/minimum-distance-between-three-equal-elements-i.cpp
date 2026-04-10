class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>>m;
        for (int i = 0; i < nums.size(); i++){
            m[nums[i]].push_back(i);
        }
        int sum = INT_MAX;
        bool distance = false;

        for (auto key:m){
            // if (key.second.size() == 3){
            //     distance = true;
            //     int n = key.second.size();
            //     int num = abs(key.second[0] - key.second[n-1]);
            //     for (int i = 1; i < n; i++){
            //         num += abs(key.second[i] - key.second[i-1]);
            //     }
                
            //     sum = min(sum, num);
            //     cout<<"yes";
                
            // }
            if (key.second.size() > 2){
                distance = true;
                // int n2 = key.second[1]? key.second[n-1]-key.second[1] > key.second[n-2]-key.second[0] : key.second[n-2];
                // int num = abs(n1-n2) + abs(n2-n3) + abs(n1-n3);
                for (int i = 1; i < key.second.size()-1; i++){
                    int n1 = key.second[i-1];
                    int n2 = key.second[i+1];
                    int num = 2*(n2-n1);
                    sum = min(sum, num);
                }
            }
            
        }

        if (distance){
            return sum;
        }
        return -1;
    }
};