#include<iostream>
using namespace std;

void read_line(char a[],int max_length){
    int i = 0;

    char ch = cin.get();  //to consume the first /n

    while(ch != '\n'){ 
        a[i] = ch;
        i++;
        if(i == (max_length - 1)){      //if the array is full --> break, last index is reserved for null
            break;
        }
        ch = cin.get();
    }
    a[i] = '\0';                        //after loop ends, put last element as \0  
    return;
}

int main(){

    // char s1[100];
    // cout << "Enter characters: " << endl;
    // cin >> s1;                               //my name is srivathsan
    // cout << "Output: " << endl;
    // cout << s1;                             //my

    cout <<  endl;

    char s2[100];
    cout << "Enter characters: " << endl;
    read_line(s2,100);                     //my name is srivathsan
    cout << "Output: " << endl; 
    cout << s2;                            //my name is srivathsan
   
   //NOTE: we can use inbuilt getline function --> cin.getline(s2,100,'\n');

return 0;
}