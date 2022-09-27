#include<iostream>
#include<string>
using namespace std;

int main(){

    string s0;                               //declaration
    string s1("hi");                         //declaration and initialization
    string s2 = "hello";                     //declaration and initialization
    string s3(s1);                           //copying s1 to s3
    string s4 = s2;                          //copying s2 to s4
    char a[] = {'a','b','c','\0'};           //character array - string
    string s5(a);

    if(s0.empty()){  
        cout << "s0 string is empty!" << endl;
    }

    s0.append("I love CPP");               //adds to the existing string
    s0 +=  " and Java";                    //concatenation
    cout << s0 << endl;
    s0.length();                        //returns length of string
    s0.clear();                         //clears the string --> length = 0

    string x = "apple";
    string y = "mango";

    cout << x.compare(y);          //-12 , because apple is lesser than mango , we can also use --> x < y
    cout << y.compare(x);         // 12 , because mango is greater than apple , we can also use --> y > x
    cout << y.compare(y);         //0 ,   because both are equal

    string c = "i want apple";
    cout << c << endl;
    int i = c.find("apple");     //starting index of the word apple
    string word = "apple";    
    int len = word.length();
    c.erase(i,len);             //erases from index i till length
    cout << c << endl;

    for(int i=0;i < c.length();i++){
        cout << c[i] << " ";          //traversing and printing string
    }

    for(auto it = c.begin();it != c.end();it++){    //using iterators, auto -->string::iterators
        cout << *(it) << " ";                      //since these use pointers we need to dereference it when we want to print
    }

    for(auto i : c){                              // for each loop/range based for loop, auto --> char
        cout << i << " ";
    }

return 0;
}