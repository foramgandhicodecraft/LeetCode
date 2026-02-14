class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        vector<double>prev_row = {(double)poured};

        for (int i = 1; i <= query_row; i++){
            vector<double>curr_row(i+1, 0);
            for (int j = 0; j < i; j++){
                double extra = prev_row[j] - 1;
                if (extra > 0){
                    curr_row[j] += extra * 0.5;
                    curr_row[j+1] += extra * 0.5;
                }
                
            }
            prev_row = curr_row;
        }

        return min(1.0, prev_row[query_glass]);
    }
};