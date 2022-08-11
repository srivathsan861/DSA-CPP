#include <iostream>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;
/*
QUESTION:
-->given N string each consists of digits and spaces
-->the no. of spaces on each string is same, no string has consecutive spaces, no string start/end with space
-->spaces are used to divide strings into columns, which can be used as keys in comparisons
-->KEY: if key is 2 , we are comparing 2nd col of both strings
-->left most column is treated as key = 1
-->comparison type: 
      ->lexiographic: 122 < 13
      ->numeric  (in this case we need to convert the string to int)
--> there is a boolean value REVERSE in the input, if true, then reverse the final output

i/p:
3                        <-- number of strings
92 022                   <-- string 1
82 12                    <-- string 2
77 13                    <-- string 3
2 false numeric          <-- key,reverse,comparison type

o/p:
82 12
77 13
92 022
*/
string ExtractTokenAtKey(string str, int key){     
	
	char *s = strtok((char*)str.c_str(), " ");   //since strtok() returns a pointer to char_array, we should convert string to char_array
	while(key>1){
		s = strtok(NULL, " ");
		key--;
	}

	return (string)s;
}

int ConvertToInt(string s){    //converts string to int
	int ans = 0;
	int p = 1;
	for(int i=s.length()-1; i>=0 ; i--){
		ans += ((s[i] - '0')*p);
		p *=10;
	}
	return ans;
}

bool numericCompare(pair<string, string> s1,pair<string, string> s2){ //comparator function for numeric sorting
	string key1, key2;
	key1 = s1.second;         
	key2 = s2.second;
	return ConvertToInt(key1) < ConvertToInt(key2);
}

bool lexioCompare(pair<string, string> s1,pair<string, string> s2){ //comparator function for lexio sorting
	string key1, key2;
	key1 = s1.second;
	key2 = s2.second;
	return key1 < key2;
}

int main(){
	
    cout << "Enter number of strings: ";

	int n ;
	cin>>n;
	cin.get(); // consuming newline char from cin>>n

    cout << "Enter the strings and other required parameters: " << endl;
	
	char a[100][100];
	for(int i=0; i<n; i++){
		cin.getline(a[i],100);
	}

	int key;
	string reversal, ordering;
	cin >> key >> reversal >> ordering;

	pair <string, string> strPair[100];   //we are using pair, first value is full string , second value has extracted value

	for(int i = 0; i<=n-1; i++){
		strPair[i].first = a[i];
		strPair[i].second = ExtractTokenAtKey(a[i], key);
	}
	
	//sorting
	if(ordering == "numeric"){
		sort(strPair, strPair+n, numericCompare);
	}
	else{
		sort(strPair, strPair+n, lexioCompare);

	}

	if(reversal == "true"){
		reverse(strPair, strPair+n);
	}

    cout << "Output: " << endl;

	// Print the output
	for(int i=0; i<=n-1; i++){
		cout << strPair[i].first << endl;
	}

    /*
    SOLUTION:
    -->tokenization using strtok()
    -->for sorting -> 2 comparators 
                     ->lexio
                     ->numeric ->in this case convert strings to integer
    -->reverse output if reverse is set true
     */

return 0;
}