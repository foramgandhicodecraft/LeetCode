class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;

        while (row < m){
            int left = 0;
            int right = n-1;

            while (left <= right) {
                int mid = left + (right-left)/2;
                if (matrix[row][mid] < target) {
                    left = mid+1;
                }
                else if (matrix[row][mid] > target) {
                    right = mid-1;
                }
                else if (matrix[row][mid] == target){
                    return true;
                }
            }
            row++;
        }

        return false;
    }
};