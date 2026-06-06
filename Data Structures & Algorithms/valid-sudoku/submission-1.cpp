class Solution {
public:
    bool check(int row, int col, char num, vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            if(board[row][i] == num) return false;
            if(board[i][col] == num) return false;
        }

        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;

        for(int i = boxRow; i < boxRow + 3; i++) {
            for(int j = boxCol; j < boxCol + 3; j++) {
                if(board[i][j] == num) return false;
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

               if(board[i][j]!='.'){
                char num = board[i][j];
                board[i][j]='.';
                if(!check(i,j,num,board)){
                    return false;
                }
                board[i][j]=num;
               }
            }
        }

        return true;
    }
};