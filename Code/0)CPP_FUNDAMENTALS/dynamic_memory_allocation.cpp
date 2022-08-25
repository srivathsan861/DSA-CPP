#include <iostream>
using namespace std;

int *fun1(){
   int fun_array1[] = {11,12,13}; //static array

   cout << "starting address of static array : " << fun_array1 << endl;    //starting address
   cout << "first element of static array inside function: " << fun_array1[0] << endl; //11

   return fun_array1;//return the starting address   (NOTE: like this we should never return a local variable)
}

int *fun2(){
   int *fun_array2 = new int[5]{0};  //dynamic array

   fun_array2[0] = 11;
   fun_array2[1] = 12;
   fun_array2[2] = 13;

   cout << "starting address of dynamic array : " << fun_array2 << endl; //starting address
   cout << "first element of dynamic array inside function: " << fun_array2[0] << endl; //11

   return fun_array2;//returns the starting address
}

int main(){

	// STATIC Memory Allocation
		
	// here arr cannot be reassigned to different data type
	int arr[100] = {0};
	cout << "Size of arr: " << sizeof(arr) << endl; //400

	// DYNAMIC Memory Allocation

    // here ptr can be used to reassign like ptr = new char[30];
	int *ptr;
	ptr = new int[100];
	cout << "Size of ptr: " << sizeof(ptr) << endl;  //returns pointer size (8)
	cout << "Size of *ptr: " <<sizeof(*ptr) << endl; //return the size of the data type which ptr points to --> (4)int
	delete [] ptr;   //you should manually delete it 
 

	int n;
    cout << "Enter the size of dynamic array: ";
	cin >> n;

	cout << "Enter the values: " << endl;

	ptr = new int[n]{0};   //initializing with 0
	for(int i=0; i<n ; i++){
		cin >> ptr[i];
		cout<< ptr[i] << " ";
	}

	delete [] ptr; //you should manually delete it

	cout << endl << "===========================================================================================" << endl;

	//CREATE 2D ARRAY USING DYNAMIC ARRAY

	int **d_arr;                  //stores the address of address of row heads array
	int row,col;                  
	cout << "Enter row size: ";
	cin >> row;
	cout << "Enter col size: ";
    cin >> col;

	d_arr = new int *[row];       //creates array of row heads
    
	for(int i=0;i < row;++i){           //2D array
		d_arr[i] = new int[col];       // each row item points to an address of another array
	}

	int val = 1;

	for(int i=0;i < row;++i){
		for(int j=0;j < col;++j){
			d_arr[i][j] = val;
			val++;
			cout << d_arr[i][j] << " ";    //output
		}
		cout << endl;
	}

	cout << "===========================================================================================" << endl;

	int *a = fun1();   //the starting address of the static array is stored
	cout << "Starting address of static array: " << a << endl; //0
	// cout << "First element of static array: "<<  a[0] << endl;

	/*
	the above line is commented because we can't print the elements from this static array because after the fun1 function call
	all the local variables will be cleared and function will be pushed out of the call stack, so we may get output as a 
	GARBAGE VALUE or SEGMENTATION FAULT or some times 1
	*/

    int *b = fun2();
	cout << "Starting address of static array: " << b << endl;
	cout << "First element of dynamic array from main: "<<  b[0] << endl;

	//in casee of dynamic array it will print the values of the array as dynamic array will persist even after function call


return 0;
}