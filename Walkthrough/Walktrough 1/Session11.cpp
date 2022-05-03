#include <stdio.h>
#include <string.h>
//https://www.cs.usfca.edu/~galles/visualization/Search.html

int linear_search(int arr[], int n, int x){
    // looping  dari awal sampai akhir
    for (int i = 0; i < n; i++)
    {
        // bandingin sama arr[i]
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

int binary_search_iter(int arr[],int low,int high,int x){
    // loop selama low <= high
    while(low<=high){
        int mid = (high + low)/2;
        // bandingin mid sama xx
        if( arr[mid] == x){
            return mid;
        }else if (arr[mid] < x){
            // area yang lebih besar
            low = mid + 1;
        }else{
            // ke daerah yang lebih kecil
            high = mid - 1;
        }
    }
    return -1;
}

int binary_search_rec(int arr[], int lo , int hi, int x){
    // base case
    if (lo <= hi){
        int mid = (hi+lo)/2;
        if(arr[mid] == x){
            return mid;
        }else if(arr[mid] < x){
            return binary_search_iter(arr,mid+1,hi,x);
        }else{
            return binary_search_iter(arr,lo,mid-1,x);
        }
    }
    return -1;
}

int binary_search_iter_str(char arr[][100],int low,int high,char x[]){
    // loop selama low <= high
    while(low<=high){
        int mid = (high + low)/2;
        // bandingin mid sama xx
        if( strcmp(arr[mid],x) ==0 ){
            return mid;
        }else if (strcmp(arr[mid],x) < 0){
            // area yang lebih besar
            low = mid + 1;
        }else{
            // ke daerah yang lebih kecil
            high = mid - 1;
        }
    }
    return -1;
}

int interpolation_search(int arr[], int lo, int hi, int x){
    while (lo <= hi)
    {
        int pos = lo + (((x - arr[lo] * (hi-lo))/(arr[hi] - arr[lo])));
        if(arr[pos] == x){
            return pos;
        }else if(arr[pos] < x){
        lo = pos + 1;
        }else{
        hi = pos - 1;
        }
    }
    return -1;
}

int interpolation_search_rec(int arr[], int lo, int hi, int x){
    if (lo <= hi){
        int pos = lo +(((x - arr[lo] * (hi-lo))/(arr[hi] - arr[lo])));
        if(arr[pos] == x){
        return pos;
        }else if(arr[pos] < x){
        return interpolation_search_rec(arr,pos+1,hi,x);
        }else{
       return interpolation_search_rec(arr,lo,pos-1,x);
        }
    }
    return -1;
}










int main (){

//Linear serch :  looping dari awal smpai akhir, bndingin sama apa yang kitamau swarch, bisa pakai array yang undorted
//binary search : devide and coquer
//Interpolation search = upgrade dari binary search
int arr[] = {21, 33, 44, 65,  96};
// char arr[][100] = {
//     "Anderson",
//     "Charlie",
//     "Erwin",
//     "Felix",
//     "Valencia"
// };

int n = sizeof(arr)/sizeof(arr[0]);

int x = 21;
// char x[]= "Erwin";

// int loc =binary_search_iter_str(arr,0,n-1,x);
int loc = interpolation_search(arr,0,n-1,x);

if(loc == -1){
    printf("not Found");
}else{
    printf("element %d found at index %d",x ,loc);
}



















    return 0;
}


