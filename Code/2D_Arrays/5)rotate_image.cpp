#include<iostream>
using namespace std;

/* 
90 deg - clockwise --> transpose and reverse columns --> reverse elements in each row
90 deg - anti-clockwise --> transpose and reverse rows --> reverse elements in each column
180 deg -->  reverse columns --> reverse elements in each row 
             reverse rows --> reverse elements in each column
*/

 void rotate_image(int a[][500],int n) {

       for(int row = 0;row < n;row++){   // reverse row --> reverse elements in each column

        int start_col = 0;
        int end_col = n-1;

        while(start_col < end_col){                    //NOTE: we can also use inbuit reverse function using STL

            swap(a[row][start_col],a[row][end_col]);
            start_col++;
            end_col--;

        }
    }

    for(int i=0;i<n;++i){               //taking transpose

        for(int j=0;j < n;++j){

            if(j > i){                     //swapping the upper and lower triangle only, because diagonal doesn't change during transpose
                swap(a[i][j],a[j][i]);
            }

        }
    }
 }

int main(){

    int a[500][500];                 //declaration
    int n = 0;                       //row size

    cout << "Enter the row/col size: ";
    cin >> n;

    cout << "Enter the values: " << endl;

    for(int row=0;row < n;row++){
        for(int col = 0;col < n; col++){
            cin >> a[row][col];             //input 2D array
        }
    }
    
    rotate_image(a,n);
    
    cout << "After rotation(90deg:anti-clock wise): " << endl;

    for(int i=0;i < n;++i){
        for(int j=0;j < n;++j){
            cout << a[i][j] << " ";           //output rotated array
        }
            cout << endl;
    }

return 0;
}