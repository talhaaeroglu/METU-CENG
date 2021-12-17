#include "the2.h"
//You may write your own helper functions here
void swapf(short unsigned int* h, short unsigned int* l){
    int temp = *h;
    *h = *l;
    *l = temp;
    
}

int partition(unsigned short* arr, long& swap, double & avg_dist, double & max_dist, int size){
    int x = arr[size-1];
    int i = -1;
    avg_dist = avg_dist*swap;
    for(int j=0; j<=size-2; j++){
        if(arr[j] >= x){
            i++;
            swapf(&arr[i],&arr[j]);
            swap++;
            if(j-i < 0){
                if(i-j > max_dist){
                    max_dist = i-j;
                }
                avg_dist += i-j;
            }
            else{
                if(j-i > max_dist){
                    max_dist = j-i;
                }
                avg_dist += j-i;
            }
        }
    }
    swapf(&arr[i+1],&arr[size-1]);
        if(i+2-size < 0){
            if(size-2-i > max_dist){
                max_dist = size-2-i;
            }
            avg_dist += size-2-i;
        }
        else{
            if(i+2-size > max_dist){
                max_dist = i+2-size;
            }
            avg_dist += i+2-size;
        }
    swap++;

    if(swap==0){
        avg_dist = 0;
    }
    else{
        avg_dist = avg_dist / swap;
    }
    return (i+1);
}

int hoareSort(unsigned short* arr, long &swap, double & avg_dist, double & max_dist, int size){
    
    int x,i,j;
    x = arr[(size-1)/2];
    i = -1;
    j = size;
    avg_dist = avg_dist*swap;
    while(true){
        do{
            j=j-1;
        }while(arr[j] < x);
        do{i = i+1;
        }while(arr[i] >x);
        if(i<j){
            swapf(&arr[i],&arr[j]);
            swap++;
            if(j-i < 0){
                if(i-j > max_dist){
                    max_dist = i-j;
                }
                avg_dist += i-j;
            }
            else{
                if(j-i > max_dist){
                    max_dist = j-i;
                }
                avg_dist += j-i;
            }            
        }
        else{
            if(swap==0){
                avg_dist = 0;
            }
            else{
                avg_dist = avg_dist / swap;
            }
            return j;
        }
    }
}

void partition3(unsigned short *arr, long &swap, long &comparison, int size, int &L, int &R){
    int i,j,p,m;
    i = 0;
    j = 0;
    p = size-1;
    
    while(i<p){
        if(arr[i]>arr[size-1]){
            comparison++;
            swapf(&arr[i],&arr[j]);
            swap++;
            i++;
            j++;
        }
        else if(arr[i] == arr[size-1]){
            p--;
            swapf(&arr[i],&arr[p]);
            swap++;
            comparison+=2;
        }
        else{
            comparison+=2;
            i++;
        }
        
    }
    m = (p-j) < (size-p) ? p-j : size-p;
    for(int a=0;a<m;a++){
        swapf(&arr[j+a],&arr[size-m+a]);
    }
    swap+=m;
    L = j;
    R = p-j;
}


void quickSort(unsigned short* arr, long &swap, double & avg_dist, double & max_dist, bool hoare, int size)
{
    //Your code here
    if(hoare == false){
        if(size>1){
            int p = partition(arr, swap, avg_dist, max_dist, size);
            quickSort(arr,swap,avg_dist,max_dist,hoare,p);
            quickSort(arr+p+1,swap,avg_dist,max_dist,hoare,size-p-1);
        }

    }
    else{
        if(size>1){
            int pi = hoareSort(arr, swap, avg_dist, max_dist, size);
            quickSort(arr, swap, avg_dist, max_dist, hoare, pi+1);
            quickSort(arr+pi+1, swap, avg_dist, max_dist, hoare, size-pi-1);
        }
    }
}

void quickSort3(unsigned short *arr, long &swap, long &comparison, int size) {
	
    //Your code here
    int L,R;
    L=0;
    R=0;
    if(size>1){
        partition3(arr,swap,comparison,size,L,R);
        quickSort3(arr,swap,comparison,L);
        quickSort3(arr+size-R,swap,comparison,R);
    }
    
    	
}









