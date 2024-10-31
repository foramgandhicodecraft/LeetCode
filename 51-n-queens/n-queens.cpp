class Solution {

public:
    bool issafe(int row, int col, vector<string>board, int n){
        int duprow = row;
        int dupcol = col;
        
        //check upper diagonal
        while (row>=0 && col>=0){
            if (board[row][col] == 'Q') return false;

            row--;
            col--;
        }
        
        //check lower diagonal
        col = dupcol;
        row = duprow;
        while (row<n && col>=0){
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        //check left row
        col = dupcol;
        row = duprow;
        while (col >= 0){
            if (board[row][col] == 'Q') return false;
            col--;
        }

        return true;
    }    

public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if (col == n){
            ans.push_back(board);
        }

        for (int row = 0; row < n; row++){
            if(issafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');

        for (int i = 0; i < n; i++){
            board[i] = s;
        }

        solve(0,board,ans,n);
        return ans;
    }
};