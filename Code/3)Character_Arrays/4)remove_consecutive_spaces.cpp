#include<iostream>
#include<cstring>
using namespace std;

/*
i/p: ccoooding
o/p: coding
*/

void remove_consecutive_duplicates(char a[]){

    int l = strlen(a);

    if(l == 0 || l == 1){        //edge case
        return;
    }

    int prev = 0;

    for(int curr = 1; curr < l;curr++){

        if(a[curr] != a[prev]){          //if curr != prev we are incrementing previous and storing curr in prev and incrementing curr
            prev++;                     
            a[prev] = a[curr];
        }
                                       //if curr == prev we are only incrementing the curr
    }
    a[prev+1] = '\0';                //last element is null            
    return;
}

int main(){

    char s1[100];

    cout << "Enter characters: " << endl;
    cin.getline(s1,100);   

    remove_consecutive_duplicates(s1);
    
    cout << "Output: " << endl;
    cout << s1;

return 0;
}