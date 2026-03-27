#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row, int col,vector<vector<int>>& board,int val){
    for(int i =0;i<board.size();i++){
        if(board[row][i] == val)
        return false;

        if(board[i][col] == val) return false;

        if(board[3*(row/3) + i/3][3*(col/3)+i%3] == val) return false;
    }
    return true;
}


bool solve(vector<vector<int>> & board){
    int n = board.size();
    for(int row = 0;row<n;row++){
        for(int col = 0;col<n;col++){
            if(board[row][col] == 0){
                for(int val = 1;val<=n;val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col] = val;
                        bool possiblesol = solve(board);

                        if(possiblesol)
                        return true;
                        board[row][col] = 0;
                    }

                   
                }
                return false;
            } 
        }
    }
    return true;
}
void printBoard(vector<vector<int>>& board){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    vector<vector<int>> board = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if(solve(board)){
        cout << "Sudoku Solved:\n";
        printBoard(board);
    } else {
        cout << "No solution exists\n";
    }
}