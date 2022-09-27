#include<iostream>
#include<cstring>
using namespace std;

int main(){

    int n;

    cout << "Enter the number of strings: ";
    cin >> n;

    char a[500];
    char largest[500];

    int len = 0;
    int largest_len = 0;

    cin.get();                  //to consume the extra \n

    for(int i=0;i < n;++i){
        cin.getline(a,500);
        len = strlen(a);
        if(len > largest_len){
            largest_len = len;          //storing the largest string length
            strcpy(largest,a);         //copying the largest array using inbuilt function
        }
    }

    cout << "The largest string is --> " << largest << endl << "Length --> " << largest_len << endl;

return 0;
}