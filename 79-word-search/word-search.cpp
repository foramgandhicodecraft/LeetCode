class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int i, j;
        //bool present = false;

        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++){
                if(dfs(i, j, board, word, 0)){
                    return true;
                } 
            }
        }

        return false;
    }

    bool dfs(int row, int col, vector<vector<char>>& board, string word, int k){
        if (k == word.size()) return true;
        
        if (k < 0 || k > word.size() || row < 0 || row >=  board.size() || col < 0 || col >= board[0].size()) return false;

        if (word[k] != board[row][col]) return false;

        char temp = board[row][col];
        board[row][col] = '/'; // mark as visited

        bool found = dfs (row+1, col, board, word, k+1) || dfs (row-1, col, board, word, k+1) || dfs (row, col+1, board, word, k+1) || dfs (row, col-1, board, word, k+1);

        board[row][col] = temp; // restore the character, can be of use to further paths

        return found;
    }

    
};