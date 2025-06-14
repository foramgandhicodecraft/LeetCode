class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int bit = 0; bit < 32; ++bit) {
            int sum = 0;
            for (int x : nums) {
                sum += (x >> bit) & 1;
            }
            result |= (sum % 3) << bit;
        }
        return result;
    }
};
