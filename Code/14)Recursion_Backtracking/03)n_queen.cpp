#include<iostream>
using namespace std;

/*
QUESTION: The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.

APPROACH:
 ->iterate on each row in a N*N matrix and CHECK whether you can place in a particular cell in a row
   ->HOW TO CHECK?
     *check whether a queen is present in upper-column,upper-left-diagonal,upper-right-diagonal
     *if YES -> return FALSE to the previous call
     *if NO -> return TRUE and try to place another queen in next row
     *repeat till row pointer reaches N (base case)
 ->NOTE: don't need to check lower-column,lower-left-diagonal,lower-right-diagonal because we are traversing each row from top,
         so there won't be any queen on up coming rows
*/

bool is_safe(int board[][10],int i,int j,int n){

    for(int row=0;row < n;row++){   //check for queen in upper-col
        if(board[row][j] == 1){
            return false;
        }
    }

    int x=i;           //storing 'i' and 'j' in a temporary variable so that we don't lose the value of 'i' and 'j' which we need again
    int y=j;

    while(x >=0 && y >= 0){         //check for queen in left-diagonal
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    
    x=i;               //re-initializing temporary variables
    y=j;

    while (x >= 0 && y < n){       //check for queen in right-diagonal
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }

return true;    //the position is safe now to place the queen after checking all the required positions
}

bool solve_N_queen(int board[][10],int i,int n){

    if(i == n){  //base case

        for(int i=0;i<n;++i){    //printing the output
            for(int j=0;j<n;j++){
                if(board[i][j] == 1){
                    cout << "Q ";
                }
                else{
                    cout << "_ ";
                }
            }
         cout << endl;
        }
    return true;
    }

    //recursive case
    //try to place the queen in the current row and call on the remaining part which will be solved by recursion

    for(int j=0;j < n;j++){ //traversing all cols.->
      
      //check if (i,j)th position is safe to place the queen or not
      if(is_safe(board,i,j,n)){

        //place the queen assuming that (i,j) is the right position
        board[i][j] = 1;

        bool next_queen_possible = solve_N_queen(board,i+1,n);  //incrementing row
        if(next_queen_possible){
            return true;
        }

        //means (i,j)th position is not the right position -> assumption is wrong
        board[i][j] = 0;  //backtracking step
      }

    }

return false;  //tried for all positions in the current row but couldn't place a queen
}

/*
VARIATION: if you are asked to print all the possible configurations of N-queens, put 'return false' in the base case instead of 'return true'
           this will help to find all other possible configurations even after finding a particular configuration.
*/

int main(){

    int n;
    cout << "Enter no. of queens:";
    cin >> n;

    int board[10][10] = {0};

    solve_N_queen(board,0,n);

return 0;
}