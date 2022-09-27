#include<iostream>
#include<cstring>
using namespace std;

char *mystrtok(char *str,char delim){
    static char *input = NULL;             //used to maintain how many tokens returned till now
    if(str != NULL){                      
        input = str;                       //first call                     
    }
    if(input == NULL){                     //bases condition
        return NULL;  //if there is no token left, then input = NULL ,we are returning NULL because till that point while loop will run
    }
    //dynamic array,to store the word --> max size is length of sentence + 1 because whole sentence can be a word
    char *output = new char[strlen(input)+1]; 
    int i=0;
    for(;input[i] != '\0';++i){
        if(input[i] != delim){          //unless a space is encountered
            output[i] = input[i];
        }
        else{
            output[i] = '\0';         //if space is encountered then end the word with NULL
            input = input + i + 1;   //for the next time input should start from next token
            return output;             
        }
    }
    //for the last word in the sentence(edge case)
    output[i] = '\0';               
    input = NULL;
    return output;
}

int main(){

    char s[500];

    cout << "Enter a sentence: " << endl;

    cin.getline(s,500);

    cout << "Output: " << endl;

    char *ptr = mystrtok(s,' ');
    cout << ptr << endl;

    while(ptr != NULL){
        ptr = mystrtok(NULL,' ');
        cout << ptr << endl;
    }

return 0;
}