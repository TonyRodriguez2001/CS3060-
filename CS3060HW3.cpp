#include <iostream>
#include <iomanip>

using namespace std;

//getModeMethod returns either the mode of the array or a -1 if
//the array has no mode
int getMode(int array[], int size);
int* makeArray(int size);

///NOTE: The assignment does not state to retrieve array values from user

int main(int argc, const char * argv[]) {
    
    //array that is passed in to the getMode() method.
    int array[] = {1, 2, 3, 4, 5, 6, 2};
    
    int mode = getMode(array, sizeof(array)/sizeof(int));
    
    if(mode != -1){
        cout << "The mode of the array is " << mode << endl;
    }
    else{
        cout << "The array has no mode." << endl;
    }
    return 0;
}


//getModeMethod returns either the mode of the array or a -1 if
//the array has no mode
int getMode(int array[], int size){

    int mostCount = 0;
    int result = 0;
    
    //stores the address of the end of the array
    int *end = array + size - 1;
    
    //outer loop traverses the array while inner loop counts the
    //occurences of each element
    for(int *ptr1 = array; ptr1 <= end; ++ptr1){
        int occurences = 0;
        
        //inner loop traversing the array while counting the number of
        //occurences of the value being pointed to by *ptr1
        for(int *ptr2 = array; ptr2 <= end; ++ptr2){
            
            if(*ptr1 == *ptr2){
                occurences++;
            }
            
        }//for(int *ptr2 = array; ptr2 <= end; ++ptr2)
        
        //the value evaluated occured more often than the previous most often
        //occuring value. The value also occured more than once.
        if(occurences > mostCount && occurences > 1){
            mostCount = occurences;
            result = *ptr1;
        }
        
    }//for(int *ptr1 = array; ptr1 <= end; ++ptr1)
    
    //there was no mode found
    if(result == 0 && mostCount == 0){
        return -1;
    }
    //a mode was found
    else{
        return result;
    }
    
}//getMode(int array[], int size)

int* makeArray(int size){
    
    int* ptr = new int[size];
    return ptr;
    
}

