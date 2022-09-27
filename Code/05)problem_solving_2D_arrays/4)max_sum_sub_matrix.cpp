#include<iostream>
using namespace std;

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
    
    //we are finding the suffix sum matrix because we know the the largest sum lies at the bottom right region of the matrix
    //NOTE: the above intuition is made on the basis that both rows and cols are sorted in the given matrix

    for(int i=n-1;i >= 0;i--){
        for(int j = m-2;j >= 0;j--){
            a[i][j] += a[i][j+1];                 //finding inplace suffix sum (col-wise addition)
        } 
    }

     for(int j=m-1;j >= 0;j--){
        for(int i = n-2;i >= 0;i--){
            a[i][j] += a[i+1][j];                //finding inplace suffix sum (row-wise addition)
        }
    }

    int sum = INT_MIN;

    for(int i=0;i < n;++i){
        for(int j=0;j < m;++j){
            sum = max(sum,a[i][j]);             //finding the max value in the suffix sum matrix
        }
    }

    //NOTE: the max value in suffix sum matrix is the max sum of a sub-matrix because it corresponds to the max value of the lower right matrix

    cout << "Max sum of a sub-matrix: ";
    cout << sum;

return 0;
}