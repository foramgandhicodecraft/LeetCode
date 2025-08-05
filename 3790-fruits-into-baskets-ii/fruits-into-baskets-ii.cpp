class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int count = 0;

        for (int i = 0; i < fruits.size(); i++){
            for (int j = 0; j < baskets.size(); j++){
                if (baskets[j] >= fruits[i]){
                    baskets[j] = 0;
                    count++;
                    break;

                }
            }
        }

        int ans = fruits.size() - count;

        return ans;
    }
};