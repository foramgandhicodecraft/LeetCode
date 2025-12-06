class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>>pascal;
        
        for (int row = 0; row < numRows; row++){
            vector<int>line;
            int res = 1;

            for (int col = 0; col < row+1; col++){
                if (col == 0 || col == row){
                    line.push_back(1);
                }
                else {
                    res = res * ((row-col)+1);
                    res = floor(res / col);
                    line.push_back(res);
                }
            }
            pascal.push_back(line);
        }

        return pascal;
    }
};