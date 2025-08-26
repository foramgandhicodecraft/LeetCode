class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        int max_d = 0;
        int area = 0;
        
        for (int i = 0; i < dimensions.size(); i++){

            if (((dimensions[i][0] * dimensions[i][0]) + (dimensions[i][1] * dimensions[i][1])) > max_d){
                max_d = (dimensions[i][0] * dimensions[i][0]) + (dimensions[i][1] * dimensions[i][1]);
                area = dimensions[i][0] * dimensions[i][1];
            }

            else if (((dimensions[i][0] * dimensions[i][0]) + (dimensions[i][1] * dimensions[i][1])) == max_d){
                area = max(area, dimensions[i][0] * dimensions[i][1]);
            }
        }

        return area;
    }
};