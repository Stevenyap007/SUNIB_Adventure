#include <stdio.h>

int bubble_sort(int arr[],int n){
    int tuker = 0;
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
               tuker++;
            }
       
        }
    }
    return tuker;   
}

int main (){

    int T,N,X,waktu_total;

    scanf("%d",&T);
    

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d",&N,&X);
        int Gerbong[N];

        for (int j = 0; j < N; j++)
        {
            scanf("%d",&Gerbong[j]);
        }

        waktu_total = bubble_sort(Gerbong,N) * X;

        printf("Case #%d: %d\n",i+1,waktu_total);

    }
    














    return 0;
}