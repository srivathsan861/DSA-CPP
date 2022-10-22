#include<iostream>
using namespace std;

/*
QUESTION: Given a M*N matrix with some cells blocked(X),we can move only forward ot downward.
          print all possible paths.
         (VARIATIONS: *find a path from sourse to dest. *count no. of possible paths)

APPROACH: 
 ->we have 2 options, if we move forward: row,col-1
 ->if we move downward: row-1,col
 ->let us consider there are 'M' rows and 'N' columns
   *[(M-1),N]  -> forward  -> until 'i' reaches destination -> i == M-1 <- base-case
   *[M,(N-1)]  -> downward -> until 'j' reaches destination -> j == N-1 <- base-case
 ->while traversing we will mark 1 in the solution matrix i.e we will assume the way we are traversing is the correct way to reach destination
 ->when we know it is not the correct case we will BACKTRACK and mark them 0
 ->NOTE:even if we successfully get a path, we will still BACKTRACK and mark 0 in the path.
        we do this to find another potential path to find the destination
*/
                                                     
bool rat_in_maze(char maze[10][10],int solution[][10],int i,int j,int m,int n){

    if(i == m && j == n){          //base case

        solution[m][n] = 1;       //marking the cell 1

        for(int i=0;i <=m;++i){      //printing the solution matrix
            for(int j=0;j <=n;++j){
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

    return true;  
    }

    if(i > m || j > n){   //to check we are traversing inside the maze or not
        return false;
    }

    if(maze[i][j] == 'X'){ //if the cell is blocked return false -> we can't reach the destination using that path
        return false;
    }

    //assume solution exists through current cell
    solution[i][j] = 1;

    bool right_success = rat_in_maze(maze,solution,i,j+1,m,n);  //incrementing j
    bool down_success = rat_in_maze(maze,solution,i+1,j,m,n);   //incrementing i

    //backtracking step
    solution[i][j] = 0; //we are writing this after the recursive call

    if(right_success || down_success){ //if we either reach the destination via forward or downward direction -> return true
        return true;
    }

return false; //if we are unable to reach the destination -> return false
}

int main(){

    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00",
    };

    int solution[10][10] = {0};
    int m=4,n=4;

    bool ans = rat_in_maze(maze,solution,0,0,m-1,n-1);
    
    if(ans == false){
        cout << "Path doesn't exist!" << endl;
    }

return 0;
}