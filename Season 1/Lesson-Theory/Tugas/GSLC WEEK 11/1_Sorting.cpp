#include <stdio.h>

void print_arr(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);

    }
    printf("\n");
}

void bubble_sort(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        
       // buat loop kedua buat ngecek masing" index 
       // tidak rerjadi swap, break
       int flag = 0;
       for (int j = 0; j < n-1-i; j++)
       {
           //ngebandingin
           if (arr[j] > arr[j+1]){
               //tukar
               int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
               flag = 1;
           }
       }
       if(flag = 0){
           break;
       } 
    }   
}

void selection_sort(int arr[],int n){
    // loop untuk n-1 kali
    for (int i = 0; i < n-1; i++)
    {
        //set minimym =  arr[i]
        int min = i ;
        // cek index yang belum di sort
        for (int j = i+1; j < n; j++)
        {
            // compare
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        // swap aar[i] sama min yang baru
        int temp = arr[i];
        arr[i] = arr[min];
        arr [min] = temp;
    }
    
}

void insertion_sort(int arr[],int n){
    // loop dari index i sampe n-1
    for (int i = 1; i < n; i++)
    {
        //set curr indexnya jadi i (extract current index)
        int curr = arr [i];
        int j;
        //cek belakang index
        for (j = i - 1; j >= 0; j--)
        {
            if (curr < arr[j]){
                arr[j+1] = arr[j];
            //ketemu yang lebih kecil
            }else{
                break;
            }
        }
        // asign arr[j+1] dengan curr
        arr[j+1] = curr;  
    }
}


int main (){

int arr_Num[] = {14,6,23,18,7,47,2,83,16,38};
int n = sizeof(arr_Num)/sizeof(arr_Num[0]);
// bubble_sort(arr_Num,n);
// selection_sort(arr_Num,n);
// insertion_sort(arr_Num,n);
print_arr(arr_Num,n);





    return 0;
}