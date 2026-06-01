class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int res = 1;
        vector<vector<int>>ans;
        
        for (int row = 0; row < numRows; row++){
            vector<int>level;
            for (int col = 0; col <= row; col++){
                if (col == 0 || col == row){
                    level.push_back(1);
                }
                else{
                    res = res * (row-col+1);
                    cout<<res<<endl;
                    res = res/col;
                    level.push_back(res);
                    
                }
            }
            ans.push_back(level);
            res = 1;
        }

        return ans;
    }
};