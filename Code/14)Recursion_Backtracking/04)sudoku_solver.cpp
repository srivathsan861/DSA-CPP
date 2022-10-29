#include<iostream>
#include<cmath>
using namespace std;

/*
QUESTION: Given a N*N sudoku where N is a perfect square, write an algorithm which finds possible solution.
          (we will have N sub-grids and each sub-grid will be of size rootof(N)*rootof(N))

SUDOKU-CONDITIONS:
 ->each row should have 0 to N 
 ->each col should have 0 to N
 ->each sub-grid should have 0 to N (HOW to check this ?)

HOW TO FIND WHETHER A NUMBER IS ALREADY PRESENT IN THE SUB-GRID ?
 ->to check whether a number is already present in the subgrid, we first need to find the starting indices of the sub-grid --> HOW?
   ->let 'i' be row pointer and 'j' be column pointer and 'sx' and 'sy' be starting indices of the sub-grid
     sx = (i/root(N))*root(N) 
     sy = (j/root(N))*root(N) 
     ->EXAMPLE CASE: let N=9, and the cell in which we want to place a number is (i,j) = 4,5
                     sx = (4/3)*3 = 1*3 = 3
                     sy = (5/3)*3 = 1*3 = 3
                     now we have found the starting point of the sub-grid, so now we can easily run a loop
                     from 'sx','sy' and traverse till (sx+3) and (sy+3) because each sub-grid is of size root(N)*root(N)
                     and we can check whether the number is preent in the sub-grid or not.

APPROACH:
 ->if all the CONDITIONS are satisfied put the number in the first empty cell -> return true (and move to next empty cell -- HOW?)
 ->if all CONDITIONS are not satisfied then the sub-grid will return false to the previous call and the previous call will try to place the
   current number in the previous empty cell. this process continues until row pointer reaches N.
 ->the next empty cell will be called in the backtracking step. (we will be skipping pre-filled values in sudoku)
*/

bool can_place(int mat[][9],int i,int j,int n,int number){

    for(int x=0;x<n;x++){ //check: rows and cols
        if(mat[x][j] == number || mat[i][x] == number){
            return false;
        }
    }

    int rn = sqrt(n);  //root(n)

    //starting indices of the sub-grid
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;

    for(int x=sx;x < sx+rn;x++){  //check: sub-grid
        for(int y=sy;y < sy+rn;y++){
            if(mat[x][y] == number){
                return false;
            }
        }
    }

return true;  //we checked the row,col and sub-grid and the number is not present so we can place the number in the current cell
}

bool sudoku_solver(int mat[][9],int i,int j,int n){

    if(i == n){   //base case

        for(int i=0;i<n;++i){      //printing the output
            for(int j=0;j<n;++j){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    return true;
    }

    if(j == n){ //row-end case
        
        //incrementing row and re-initializeing col to 0
        return sudoku_solver(mat,i+1,0,n); 
    }

    if(mat[i][j] != 0){

        //skipping pre-filled value
        return sudoku_solver(mat,i,j+1,n);
    }

    //recursive case
    //fill the current cell with possible options

    for(int number=1;number <= n;++number){

        if(can_place(mat,i,j,n,number)){

            //assuming we placed it right
            mat[i][j] = number; 

        bool could_we_solve_futher = sudoku_solver(mat,i,j+1,n); //incrementing col pointer
        if(could_we_solve_futher){
            return true;
        }
        }
    }
    
    //our assumption is wrong
    mat[i][j] = 0; //backtracking step

    return false;  //we are not able to solve using this configuratio9n
}

int main(){
    
    int mat[9][9] =  
    {{3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0} };

    sudoku_solver(mat,0,0,9);

return 0;
}