#include<iostream>
#include<cstring>
using namespace std;

/*
QUESTION: replace 'pi' with 3.14

EXAMPLE: i/p: xpighpimpipi
         o/p: x3.14gh3.14m3.143.14

VISUALIZATION:            i  i+1 i+2 
            | a | b | c | p | i | x | y | z |

            *consider it as an char array now our 'i' is on 'p', so check whether 'i+1' = 'i' so that it forms "pi"
            *for every "pi" we need 4 places because we want to insert value of "3.14"
            *we can acomodate "3." in the place of "pi" but we need 2 more extra places to accomodate "14"
            *so we should shift all characters after 'i+1' to 2 positions

            | a | b | c | 3 | . | 1 | 4 | x | y | z |

            *keep on repeating it until 'i' reaches '/0'
            *if 'i' and 'i+1' is not qual to 'p' and 'i' respectively -> keep on traversing, i = i + 1

*/

void replace_pi(char a[],int i){

    if(a[i] == '\0' || a[i+1] == '\0'){   //base case
        return;
    }

    if(a[i] == 'p' && a[i+1] == 'i'){

        int j=i+2;

        while(a[j] != '\0'){  //take 'j' to the end of the array
            j++;
        }

        while(j >= i+2){     //shifting right to left
            a[j+2] = a[j];   //dry-run this part for better understanding
            j--;
        }
        
        //replacing values
        a[i] = '3';   
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';

        replace_pi(a,i+4);   //recursive call for remaining part of the array
    }
    else{
        replace_pi(a,i+1);   //if 'i' != "p", go to next position and check
    }

return;
}

int main(){

    char s[] = "xpighpimpipi";

    replace_pi(s,0);

    cout << "After replacing 'pi' with '3.14':" << endl << s;

return 0;
}