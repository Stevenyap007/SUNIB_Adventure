#include <stdio.h>

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

int main () {

    int T,N;
    
    
    scanf("%d",&T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d",&N);
        int mahasiswa[N];

        for (int j = 0; j < N; j++)
        {
            scanf("%d",&mahasiswa[j]);
        }

        bubble_sort(mahasiswa,N);
        
        int count[N] = {0};
        int middle = (N / 2) - 1;
        for(int j = 0; j < N - 1; j++){
            if(j < middle){
                count[j] = mahasiswa[j + 1] - mahasiswa[j];
            } else if(j == middle){
                count[j] = 0;
            } else if(j > middle){
                count[j] = mahasiswa[j + 1] - mahasiswa[j];
            }
        }


        int max = 0;
        for (int l = 0; l < N  ; l++)
        {
            if(max < count[l]){
                max = count[l];
            }
        }

        printf("Case #%d: %d\n",i+1,max);
        
        
        
        
    }

    
    












    return 0;
}

// baris[2][middle];

        // for (int k = 0; k < 2; k++)
        // {
        //     for (int l = 0; l < middle; l++)
        //     {
        //         if(k == 0){
        //             baris[k][l] = mahasiswa[i];
        //         }else if (k == 1){
        //             baris[k][l] = mahasiswa[i+3];
        //         }  
        //     }
        // }
        
        // for (int m = 0; m < 2; m++)
        // {
        //     for (int n = 0; n < middle; n++)
        //     {
        //         baris[m][n+1] - baris[m][n] = count;
        //     }
            
        // }