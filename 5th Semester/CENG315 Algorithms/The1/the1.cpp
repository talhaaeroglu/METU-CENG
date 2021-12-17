#include "the1.h"

//You can add your own helper functions
void swapf(int&h, int&l){
    int temp = h;
    h = l;
    l = temp;
}
void mergesort(int* arr1, int* arr2, int* arr3, int size1, int size2, long &comp){
    int i=0,j=0,k=0;
    while(i<size1 && j<size2){
        if(arr1[i] < arr2[j]){
            arr3[k] =arr1[i];
            i++;
        }
        else if(arr1[i] == arr2[j]){
            arr3[k] = arr1[i];
            i++;
            
        }
        else{
            arr3[k] =arr2[j];
            j++;
        }
        k++;
        comp+=1;
    }
    while(i<size1){
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    while(j<size2){
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}




int sillySort(int* arr, long &comparison, long & swap, int size) 
{

    int num_of_calls=1;
	
	//Your code here

	if(size < 4){
        if(size == 2){
	        if(arr[0] > arr[1]){
	            swapf(arr[0], arr[1]);
	            swap+=1;
	        }
            comparison+=1;
	    }
	}
	else{
    	num_of_calls += sillySort(arr, comparison, swap, size/2);
        num_of_calls += sillySort(arr+(size/4), comparison, swap, size/2);
        num_of_calls += sillySort(arr+(size/2), comparison, swap, size/2);
        num_of_calls += sillySort(arr, comparison, swap, size/2);
        num_of_calls += sillySort(arr+(size/4), comparison, swap, size/2);
        num_of_calls += sillySort(arr, comparison, swap, size/2);
	    
	    
	}
	
	return num_of_calls;
}


int crossMergeSort(int *arr, long &comparison, int size)
{
    int* h1 = new int[size/2];
    int* h2 = new int[size/2];
	int num_of_calls=1;
	
	// Your code here
	if(size < 4){
        if(size == 2){
	        if(arr[0] > arr[1]){
	            swapf(arr[0], arr[1]);
	        }
            comparison+=1;
	    }
	}
	else{
    	num_of_calls += crossMergeSort(arr, comparison, size/4);
        num_of_calls += crossMergeSort(arr+(size/4), comparison, size/4);
        num_of_calls += crossMergeSort(arr+(size/2), comparison, size/4);
        num_of_calls += crossMergeSort(arr+(size*3/4), comparison, size/4);
        mergesort(arr,arr+(size/2),h1,size/4,size/4,comparison);
        mergesort(arr+(size/4),arr+(size*3/4),h2,size/4,size/4,comparison);
        mergesort(h1,h2,arr,size/2,size/2,comparison);
	   	  
	    
	}

	
	
	
	

	return num_of_calls;
	
}
















