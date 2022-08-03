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
    
    int val=1;                

    cout << "2D-array: " << endl;

    for(int row=0;row < n;row++){          //row-wise traversal-> for each row we are moving m col.

        for(int col=0;col < m;col++){

            a[row][col] = val;            //filling the matrix with val(val increases by one row-wise)
            val +=1;                      //incrementing val
            cout << a[row][col] << " ";         // print the 2d array

        }
        cout << endl;
    }

return 0;
}