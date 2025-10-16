class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        map<int, int>mode;
        
        for (int num:nums){
            mode[((num%value)+value)%value] += 1;
        }

        int count = 0;
        while (mode.find(count%value) != mode.end()){
            mode[count%value]--;
            if (mode[count%value] == 0){
                mode.erase(count%value);
            }
            count++;
        }

        return count;
    }
};