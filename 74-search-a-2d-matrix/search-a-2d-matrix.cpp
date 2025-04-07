class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;

        while (row < n){
         int low = 0;
         int high = m-1;

         while (low <= high){
            int mid= low + (high - low) / 2;
            
            if (matrix[row][mid] == target ){
                return true;
            }
            else if (matrix[row][mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
         }

         row++;
        }

        return false;
    }
};