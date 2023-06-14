#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//concat()
int* concat(int* arr1, size_t size1 , int* arr2 , size_t size2 ){
    int* arr = (int*)calloc( size1+size2 , sizeof( int) );
    for ( int i = 0 ; i < size1 ; ++i) {
            arr[i] = arr1[i];
    }
    for (int i = 0 ; i < size2 ; ++i ) {
            arr[i+size1] = arr2[i];
    }
    return arr;
}

//every()

bool every(int* arr, size_t size , bool (*callback)(int)){
    for (int i = 0 ; i < size ; ++i) {
        if (!callback(arr[i])) {
             return false;
         }
    }
    return true;
}   
//filter
int* filter(int* arr, size_t size, bool (*condition)(int)){
    size_t rsize= 0;    
    for  (int i = 0 ; i < size ; ++i) {
            condition(arr[i]) ? ++rsize: rsize;
    }
    int* rarr = (int*)calloc( rsize, sizeof(int));
    for (int i = 0 , j = 0 ; i < size ; ++i) {
        if (condition(arr[i])) {
            rarr[j++] = arr[i];
        }
    }
    return rarr;
}
//forEach
void forEsch( int * arr, size_t size , void (*callback)(int i)){
    for( int i=0 ; i< size ; ++i) {
        callback( arr[i]);
    }
}
//indexOf
int indexOf(int* arr, size_t size, int target){
    for (int i = 0 ; i < size ; ++i) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

//lastIndexOf
int lastIndexOf(int* arr, size_t size, int target){
    for (int i = size-1 ; i >= 0 ; --i) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

//map
int* map(int* arr, size_t size , int (*operation)(int)){
    int* narr = (int*)calloc( size, sizeof(int));
    for (int i = 0 ; i < size; ++i) {
        narr[i] = operation( arr[i]);
    }
    return narr;
}

//reduce
int reduce(int* arr, size_t size , int (*operation) (int, int), int initval){
    int accumlator = initval;
    for (int i = 0 ; i < size; ++i) {
        accumlator = operation( accumlator, arr[i]);
    }
    return accumlator;
}
//reverce
void reverce(int* arr, size_t size){
    int tmp = 0;
    for (int i = 0 ; i < size/2 ; ++i) {
        tmp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - i - 1 ] = tmp;
    }
}

//slice
int* slice(int* arr, size_t size, size_t start, size_t end){
    if( end < start || end > size-1) {
        return NULL;
    }
    int* narr = (int*)calloc( end - start , sizeof(int));
    for( int i = start, j =0 ; i <= end ; ++i) {
        narr[j++] = arr[i];
    }
    return narr;
}

//some
bool some(int* arr, size_t size, bool (*condition)(int)){
    for (int i = 0 ; i < size ; ++i) {
        if (condition(arr[i])) {
           return true;
        }
    }
    return false;
} 

void sort(int* arr, size_t size, void(*sortmethod)(int*,size_t)){
    sortmethod(arr, size);
}

void bobble(int* arr , size_t size){
    for(int i = 0 ; i < size ; ++i) {
       bool sorted = false;
       for(int j = 0 ; j < size-i-1; ++j) {
            if(arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                sorted = true;
             }
            if(!sorted) {
                return;
            }
        }
    }
}

void fill(int* arr, size_t size, int val, size_t start){
    for(int i = start ; i <size ; ++i) {
        arr[i] = val;
    }
}   

int find(int* arr, size_t size, bool (*condition)(int)){
    for (int i = 0 ; i < size ; ++i) {
        if( condition(arr[i])) {
            return i;
        }
    }
    return 0;
}
size_t filndIndex(int* arr, size_t size, bool (*condition)(int)){
    for (int i = 0 ; i < size ; ++i) {
        if (condition(arr[i])) {
            return i;
        }
    }
    return -1;
}
size_t filndLastIndex(int* arr, size_t size, bool (*condition)(int)){
    for (int i = size-1 ; i >=0 ; ++i) {
        if (condition(arr[i])) {
            return i;
        }
    }
    return -1;
}
bool inclues(int* arr, size_t size, int target){
    for (int i = 0 ; i < size ; ++i) {
        if(arr[i] == target) {
            return true;
        }
    }
    return false;
}
char* join(char** arr, size_t size){
    size_t total = 0;
     for (int i = 0 ; i < size ; i++) {
        total+= strlen(arr[i]);
    }
    char* str = (char*) calloc(total, sizeof(char));
    for (int i = 0 ; i < size ; ++i) {
        strcpy(str, arr[i]);
    }
    return str;
}
int* with(int* arr, size_t size , size_t index, int val){
    int* target = (int*)calloc(size, sizeof(int));
    target[index] = val;
    return target;
}
int main()
{
}
