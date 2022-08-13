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

    int prefix_sum[500][500];

    prefix_sum[0][0] = a[0][0];                //first element of prefix sum array and normal array is same

     for(int i=0;i < n;++i){
      prefix_sum[i][0] = a[i][0];
     }

     for(int j=0;j < m;++j){
      prefix_sum[0][j] = a[0][j];
     }

     for(int i = 0;i<n;i++){
        for(int j = 1;j<m;j++){
            prefix_sum[i][j] = prefix_sum[i][j-1]+a[i][j];
        }
    }

     for(int i = 0;i<m;i++){
        for(int j =1;j<n;j++){
            prefix_sum[j][i] = prefix_sum[j-1][i]+prefix_sum[j][i];
        }
    }

    // for(int i=1;i < n;++i){
    //       prefix_sum[0][i] = prefix_sum[0][i-1] + a[0][i];
    // }

    // for(int i=1;i < m;++i){
    //       prefix_sum[i][0] = prefix_sum[i-1][0] + a[i][0];
    // }

    // for(int i=1;i < n;++i){
    //     for(int j=1;j < m;++j){
    //          prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] + a[i][j] - prefix_sum[i-1][j-1];
    //     }
    // }

    int sum = 0;

    for(int tli = 0;tli < n;tli++){                    //considering each value in a row as  top-left i value
        for(int tlj = 0;tlj < m;tlj++){                //considering each value in a col as  top-left j value
            for(int bri = tli; bri < n;bri++){         //considering each i value starting from top-left in a row as  bottom-right i value
                for(int brj = tlj;brj < m;brj++){      //considering each j value starting from top-left in a row as  bottom-right j value
                    sum += prefix_sum[bri][brj] - prefix_sum[tli-1][brj] - prefix_sum[bri][tlj-1] + prefix_sum[tli-1][tlj-1];
                }
            }
        }
    }
    cout << "Sum of all sub-matrices: ";
    cout << sum;


    // cout << "Output: " << endl;
    // for(int i=0;i < n;++i){
    //     for(int j=0;j < m;++j){
    //         cout << prefix_sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }

return 0;
}