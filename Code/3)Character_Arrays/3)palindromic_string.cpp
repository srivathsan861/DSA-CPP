#include<iostream>
#include<cstring>
using namespace std;

bool palindromic_string(char a[]){
       //checking --> if the current first and last element is equal or not

       int i = 0; 
       int j = strlen(a)-1;

       while(i < j){

        if(a[i] == a[j]){
            i++;
            j--;
        }else{
            return false;
        }

       }
    return true;
}

int main(){

    char s1[100];

    cout << "Enter string: " << endl;
    cin.getline(s1,100);               //inbuilt getline function --> gets input until \n is hit and also accepts spaces

    if(palindromic_string(s1)){
        cout << s1  << " is a palindromic string" << endl;
    }else{
        cout << s1 << " is not a palindromic string" << endl;
    }

return 0;
}