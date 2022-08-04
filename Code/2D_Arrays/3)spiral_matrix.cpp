#include<iostream>
using namespace std;

/* 
i/p:
1 2 3 
4 5 6
7 8 9

o/p:
1 2 3 6 9 8 7 4 5
*/

int main(){

    int a[500][500];                 //declaration
    int n = 0;                       //row size
    int m = 0;                      //col size

    cout << "Enter the row size: ";
    cin >> n;
    cout <<"Enter the col size: ";
    cin >> m;
    cout << "Enter the values: " << endl;
    for(int row=0;row < n;row++){
        for(int col = 0;col < m; col++){
            cin >> a[row][col];             //input 2D array
        }
    }

    cout << "Spiral order: " << endl;
    
    int start_row = 0;
    int start_col = 0;
    int end_row = n-1;
    int end_col = m-1;

    while(start_row <= end_row && start_col <= end_col){  //repeat the below steps until this condition

    for(int i = start_col; i <= end_col;i++){      //traversing the first row
        cout << a[start_row][i] << " ";
    }
    start_row++;                                  //incrementing start_row

    for(int i = start_row; i <= end_row;i++){   //traversing last column downwards
        cout << a[i][end_col] << " ";
    }
    end_col--;                                 //decrementing end_col

    if(end_row > start_row){                     //removes the repeated traversal during a non square matrix

    for(int i = end_col; i >= start_col;i--){   //traversing the bottom row from right to left
        cout << a[end_row][i] << " ";
    }
    end_row--;                                  //decrementing end_row

    }
    
    if(end_col > start_col){                     //removes the repeated traversal during a non square matrix

    for(int i = end_row; i >= start_row;i--){    //traversing the first column from bottom to top
       cout << a[i][start_col] << " ";
    }
    start_col++;                                 //incrementing the start_col

    }

    }

return 0;
}