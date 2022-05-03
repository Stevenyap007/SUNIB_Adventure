#include <stdio.h>

void bubble_sort(long long int arr[],long long int n){
    for (int i = 0; i < n; i++)
    {
        
       // buat loop kedua buat ngecek masing" index 
       // tidak rerjadi swap, break
       for (int j = 0; j < n-1-i; j++)
       {
           //ngebandingin
           if (arr[j] > arr[j+1]){
               //tukar
               long long int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j+1] = temp;
               
           }
       } 
    }   
}

int  main (){

    int N;
    long long int Jojo_power;
    
    int respect = 0;

    scanf("%d",&N);
    long long int Boss_power[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%lld",&Boss_power[i]);
    }
    int size = sizeof(Boss_power)/sizeof(Boss_power[0]);
    bubble_sort(Boss_power,size);


    scanf("%lld",&Jojo_power);
    for(int j = 0; j < N; j++){
        if(Jojo_power >= Boss_power[j]){
            Jojo_power -= Boss_power[j];
            respect++;
        }
    }

    printf("%d\n",respect);

    return 0 ;
}