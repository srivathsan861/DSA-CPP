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

    for(int tli = 0;tli < n;tli++){                    //considering each value in a row as  top-left i value
        for(int tlj = 0;tlj < m;tlj++){                //considering each value in a col as  top-left j value
            for(int bri = tli; bri < n;bri++){         //considering each i value starting from top-left in a row as  bottom-right i value
                for(int brj = tlj;brj < m;brj++){      //considering each j value starting from top-left in a row as  bottom-right j value
                    for(int i = tli;i <=bri;i++){      //traversing from top-left i till bottom-right i (col-wise or width)
                        for(int j = tlj;j <= brj;j++){ //traversing from top-left j till bottom-right j (row-wise or length)
                             sum += a[i][j];           //getting the sub-array sum
                        }
                    }
                }
            }
        }
    }

    cout << "Sum of all sub-matrices: ";
    cout << sum;

    /* INTUITIION:
    --> each sub-array looks like a rectange, so if we find top-left and bottom-right of the rectangle we can find the area of the rectangle
    -->that is firstly we should find the 4 coordinates, top-left(x1,y1) and bottom-right(x2,y2)
    -->(x2 - x1 + 1) gives breadth of the rectangle
    -->(y2 - y2 +  1) gives length of the rectangle
    -->using this we can find the area of all rectangles (each rectangle is a sub-matrix)
    */

return 0;
}