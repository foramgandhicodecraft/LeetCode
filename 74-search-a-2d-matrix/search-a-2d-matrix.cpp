class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;

        while (row < m){
            int low = 0;
            int high = n-1;

            while (low <= high){
                int mid = low + (high-low)/2;
                if (matrix[row][mid] == target){
                    return true;
                }
                else if (matrix[row][mid] < target){
                    low = mid+1;
                }
                else if (matrix[row][mid] > target){
                    high = mid-1;
                }
            }

            row++;
        }

        return false;
    }
};