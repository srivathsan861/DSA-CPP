#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool compare(string a,string b){             //comparator function

    if(a.length() == b.length()){           // if lengths are equal --> sort lexicographically 
        return a < b;
    }
    return a.length() > b.length();       //else sort using length(descending)

}

int main(){

    int n;

    cout << "Enter number of strings: ";
    cin >> n;                               
    
    string a[500];

    cout << "Enter the strings: " << endl;

    cin.get();                              

    for(int i=0;i < n;++i){
        getline(cin,a[i]);           //cin.getline() won't work here with strings
    }
    
    sort(a,a+n,compare);            //this inbuilt sort function gets custom sorting function as input parameter

    cout << "After sorting: " << endl;

    for(int i=0;i < n;++i){
        cout << a[i] << endl;     //output
    }

return 0;
}