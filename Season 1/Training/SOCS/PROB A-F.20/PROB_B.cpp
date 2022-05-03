#include <stdio.h>

void bubble_sort(int arr[],int size){\
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i -1; j++)
        {
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    } 
}

int min(int arr[],int size){
    int min = 1000000;
    for (int i = 0; i < size; i++)
    {
        int selisih = arr[i] - arr[i+1];
        if(selisih < min){
            min = selisih;
        }
    }
    return min;
}

int main(){

    int T,N;
    scanf("%d",&T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d",&N);
        int Tahun[N];
        for (int j = 0; j < N; j++)
        {
            scanf("%d",&Tahun[j]);
        }
        bubble_sort(Tahun,N);
        printf("Case #%d: %d\n",i+1,min(Tahun,N-1));
    }
    





    return 0;
}