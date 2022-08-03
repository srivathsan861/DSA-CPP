#include<iostream>
using namespace std;

/* 
i/p:
1 4 7 10
2 5 8 11
3 6 9 12

o/p:
1 2 3 6 5 4 7 8 9 12 11 10
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

    cout << "Wave print :" << endl;

    for(int col = 0;col < m;col++){         //col-wise traversal-> for each col we are moving n row.

        if(col%2 == 0){                    //checking index is odd or even

        for(int row = 0;row < n;row++){   //index even --> traverse top-down
            cout<< a[row][col] << " ";          
        }

        }
        else{

            for(int row = n-1;row >= 0; row--){ //index odd --> traverse bottom-up
                cout << a[row][col] << " ";  
            }
        }
    }

return 0;
}