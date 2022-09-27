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

    int sum = 0;

    for(int i=0;i < n;++i){
        for(int j=0;j < m;++j){
             sum += a[i][j] * ((i+1)*(j+1))*((n-i)*(m-j));
            // current element * no. of sub matrices this element is present = contibution of that element in sum of sub-matrices
        }
    }

    cout << "Sum of all sub-matrices: ";
    cout << sum;

return 0;
}