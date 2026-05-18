class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>>pascal;
        int res;

        for (int i = 0; i < numRows; i++){
            res = 1;
            vector<int>row;
            for (int j = 0; j < i+1; j++){
                if (j == 0 || j == i){
                    row.push_back(1);
                } else {
                    res = res*(i-j+1);
                    res = floor(res/j);
                    row.push_back(res);
                }
                
            }
            pascal.push_back(row);
        }

        return pascal;
    }
};