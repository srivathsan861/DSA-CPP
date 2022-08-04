#include<iostream>
using namespace std;

void staircase_search(int a[][500],int n,int m,int k){

    if (n == 0 && m == 0){
        cout << "Matrix is empty!";
        return;
    }

    if(k < a[0][0] || k > a[n-1][m-1]){   //since both rows and cols are sorted , 0th index is the smallest and last element is the largest
        cout << "Element not found!";
        return;
    }

    int i = 0;                     //first index
    int j = m -1;                  //last index  

    while(i < n && j >= 0){
          
          //checks
          if(a[i][j] == k){     
            cout << "Target indices: " << i << " , " << j;
            return;
          }
          else if(a[i][j] > k){
                 j--;
          }else if(a[i][j] < k){
            i++;
          }

    }
    cout << "Element not found!";
}

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

    int k = 29;

    staircase_search(a,n,m,k);


return 0;
}