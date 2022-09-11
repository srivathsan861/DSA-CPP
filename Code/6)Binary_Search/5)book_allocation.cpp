#include<iostream>
#include<climits>
using namespace std;

/*
 ->you are given number of pages in 'N' different books and 'M' number of students
 ->books are arranged in ascending order of number of pages
 ->every student should have atleast one book
 ->allocation should be contigeous
 ->we can't split the books
 ->allocation should be in such a way that the maximum no. of pages assigned to a student is minimum
 ->find the value of minimum of maximum pages
*/

bool can_read_book(int arr[],int books,int total_students,int max_capacity_to_read){ //max_capacity_to_read == mid

    int student = 1;             //one student will be assigned first, so it starts from one        
    int page_read = 0;          //currently that student didn't read any page

    for(int i=0;i < books;++i){

        if(page_read + arr[i] > max_capacity_to_read){  //adding books/pages to the first student until he reaches his max capacity to read

            student++;                                 //after max capacity of that student is over,we bring another student
            page_read = arr[i];                       //assign the current book to new student which the previous student was not able to complete

            if(student > total_students){            //if no. of students is greater than given no. of students, return false         
                return false;       
            }
            else{
                page_read += arr[i];              //else make the student read and increment no. of pages read
            }

        }
    }

 return true;
}

int find_page(int arr[],int books,int students){

    if(books < students){
        return -1;                  //no such configuration is possible
    }

    int start = arr[books-1];   //since we should find min of max, highest page book must be read by some student
                                //that is lower bound of the seaerch space is last element of array(we can also use 0 as lower bound)
    int end = 0;

    for(int i=0;i < books;++i){
        end += arr[i];          //the upper bound of the search space is -> one student reading all books/pages
    }
    
    int ans = INT_MAX;        

    while(start <= end){

        int mid = (start+end)/2;

        bool can_read = can_read_book(arr,books,students,mid);

        if(can_read){              //if a student can read given no. of pages then it is a potential ans
            ans = min(ans,mid);   //so store the ans and if you get a more minimum ans update the ans
            end = mid-1;         //since we need to find the minimum bring the end to mid-1
        }
        else{
            start = mid+1;    //if the students can't be divided according to the constraint -> start = mid+1
            //exapmple: if student constraint is 2, but you used 3 students then make start = mid+1
        }

    }
   return ans;
}

int main(){

    int t;      //no. of test cases
    cin >> t;

    for(int i=0;i < t;++i){

        int books,students;
        cin >> books >> students;

        int arr[1000];

        for(int j=0;j < books;++j){
            cin >> arr[books];           //input no. of pages 
        }

        cout << find_page(arr,books,students);
    }

return 0;
}