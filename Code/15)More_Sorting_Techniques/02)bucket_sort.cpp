#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
QUESTION: Given student's marks and names sort them on the basis of marks using bucket sort

NOTE: Bucket sort is mainly useful when input is uniformly distributed over a range

TRY IT: Sort a large set of floating point numbers which are in range from 0.0 to 1.0 and are uniformly distributed across the range. 
        How do we sort the numbers efficiently?
*/

class Student{
    public:
    int marks;
    string name;
};

void bucket_sort(Student s[],int n){

    //assuming marks are in range 0 to 100
    vector<Student> v[101];

    for(int i=0;i < n;++i){
        
        //getting student marks and pushing the student data in the mark index of the vector
        int m = s[i].marks;     
        v[m].push_back(s[i]);

    }

    //iterate over the vector and print the students on the basis of their marks
    for(int i=100;i >= 0;i--){   //descending

        for(auto it = v[i].begin(); it != v[i].end(); ++it){
            cout << (*it).marks << " " << (*it).name << endl;
        }

    }
}

int main(){

    Student s[100];
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for(int i=0;i < n;++i){
        cin >> s[i].marks >> s[i].name;
    }
    
    cout << "After sorting: " << endl;
    bucket_sort(s,n);

return 0;
}