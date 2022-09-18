#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    //declaration and initialization of vectors
    vector<int> a;
    vector<int> b(5,10);                       //10 10 10 10 10
    vector<int> c(b.begin(),b.end());         //copying vector b to c
    vector<int> d{1,2,3,10,14};         

    //3 ways to iterate over vectors

    cout << "Printing vector d: " << endl;

    for(int i=0;i < d.size();++i){         //.size() and .length() give size of the vector
        cout << d[i] << " " ;
    }
    cout << endl;

    for(auto it = d.begin();it != d.end();it++){  //auto = vector<int>::iterator
        cout << (*it) << " ";
    }
    cout << endl;

    for(int x : d){                     //range based for loop/for each loop
        cout << x << " ";
    }
    cout << endl;
    
    //insert in vector
    vector<int> v;
    for(int i=0;i < 5;++i){
        v.push_back(i);    //while doing push back every single time the size of the vector gets doubled(costly operation)
    }
    
    /*
    understand the difference between vector 'v' and vector 'd' at memory level:
    v.size() = 5 ->has 5 elements
    v.capacity = 8 -> because each time we insert using push_back the capacity increases
    but in the case of vector 'd' both size and capacity is 5
    */

   //some methods on vector
   v.push_back(16);                    //most of the timr o(1)
   v.pop_back();                       //remove last element
   v.insert(v.begin()+3,100);          //100 will be inserted after 3 elements
   v.insert(v.begin()+3,4,100);        //100,100,100,100 will be inserted after 3 elements
   v.erase(v.begin()+3);              //removes the 3rd element
   v.erase(v.begin()+2,v.begin()+5);  //index 2 to 5 is deleted
   v.clear();                         //removes all elements
// v.empty();                         returns true if the vector is empty

   /*
   there is another method called .resize() and let's see how it will affect the size() and capacity:
   suppose the current size = 5 and capacity = 10 and v.resize(8) is performed -> size = 8, capacity = 10
   suppose the current size = 5 and capacity = 10 and v.resize(18) is performed -> size = 18, capacity = 18
   */

  //avoid doubling while using vector.push_back:
  vector<int>z;
  z.reserve(1000);              //for first 1000 elements size won't be doubled, size will be 1000
  for(int i=0;i < 5;++i){
    z.push_back(i);
  }

  cout << "Printing vector z: " << endl;

  for(int x : z){
    cout << x << " ";
  }

  cout << endl << "Size of vector z: " << z.size() << endl << "Capacity of vector z: " << z.capacity();

return 0;
}