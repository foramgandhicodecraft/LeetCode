class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int k;
        sort(piles.begin(), piles.end());
        int pile_max = piles[piles.size()-1];
        int right = pile_max;
        int left = 1;
        int ans = INT_MAX;

        while (left <= right){
            int mid = left + (right - left)/2;
            k = mid;
            double count = 0;

            for (int i = 0; i < piles.size(); i++){
                count += (piles[i]+k-1)/k;
            }

            if (count <= h){
              ans = min(ans, k);
              right = mid-1;
            }

            else if (count > h)
              left = mid+1;
        }     

        return ans;  
    }
};