#include "the3.h"
// do not add extra libraries here


/*
    arr       : array to be sorted, in order to get points this array should contain be in sorted state before returning
    ascending : true for ascending, false for descending 
    n         : number of elements in the array
    l         : the number of characters used in counting sort at each time
    
    you can use ceil function from cmath
    
*/
/*int convert(std::string str, int l){
    int len = str.length();
    int result = 0;
    for(int i=0; i<l; i++)
    {            
        result += pow(26,i)*((int)str[l-i-1]-65);
    }

    return result;
}*/

int countingSort(std::string arr[], int k, int l, int cur, bool asc){
    int iterator = 0;
    int result = 0;
    int size = (int)pow(26,l);
    std::string* C = new std::string[k];
    int array[size] = {0};
    if(asc){
        for(int i=0; i<k; i++){
            result = 0;
            for(int j=0; j<l; j++){
                result+=(int(arr[i][cur-j])-65)*(int)pow(26,j);
            }
            iterator++;
            array[result]++;
        }
        for(int i=1; i<size; i++){
            array[i] += array[i-1];
            iterator++;
        }
        for(int i=k-1; i>=0; i--){
            result = 0;
            for(int j=0; j<l; j++){
                result+=(int(arr[i][cur-j])-65)*(int)pow(26,j);
            }
            C[array[result]-1] = arr[i];
            array[result]--;
            iterator++;
        }
        for(int i=0; i<k; i++){
            arr[i] = C[i];
            iterator++;
        }
    }
    else{
        for(int i=0; i<k; i++){
            result = 0;
            for(int j=0; j<l; j++){
                result+=(int(arr[i][cur-j])-65)*(int)pow(26,j);
            }
            iterator++;
            array[size-1-result]++;
        }
        for(int i=1; i<size; i++){
            array[i] += array[i-1];
            iterator++;
        }
        for(int i=k-1; i>=0; i--){
            result = 0;
            for(int j=0; j<l; j++){
                result+=(int(arr[i][cur-j])-65)*(int)pow(26,j);
            }
            C[array[size-1-result]-1] = arr[i];
            array[size-1-result]--;
            iterator++;
        }
        for(int i=0; i<k; i++){
            arr[i] = C[i];
            iterator++;
        }
    }
    return iterator;
    
}


int radixSort(std::string arr[], bool ascending, int n, int l){
    int x = arr[0].length();
    int res = 0;
    for(int i=0; i<x; i+=l){
        if(x-i < l){
            l = x-i;
        }
        res+=countingSort(arr, n, l, x-i-1, ascending);
        res++;
    }
    return res;    
    
}
