#include <stdio.h>

void print_arr(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);

    }
    printf("\n");
}

void bubble_sort(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        
       // buat loop kedua buat ngecek masing" index 
       // tidak rerjadi swap, break
       
       for (int j = 0; j < n-1-i; j++)
       {
           //ngebandingin
           if (arr[j] > arr[j+1]){
               //tukar
               int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
              
           }
       }

    }   
}

int main (){

    int T,N,X;

    scanf("%d",&T);
    

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d",&N,&X);
        int Gerbong[N];

        for (int j = 0; j < N; j++)
        {
            scanf("%d",&Gerbong[j]);
        }
        
        




        int size = sizeof(Gerbong)/sizeof(Gerbong[0]);
        printf("%d\n",size);
        bubble_sort(Gerbong,size);
        print_arr(Gerbong,size);
        
    }
    














    return 0;
}