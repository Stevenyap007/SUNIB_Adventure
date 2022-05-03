#include <stdio.h>
#include <string.h>
// sorting : https://visualgo.net/en/sorting


struct Mahasiswa
{
    char nama[50];
    int nilai;
};

//print array indexes
void print_arr(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);

    }
    printf("\n");
}

void print_arr_struct(Mahasiswa arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("Nama : %s\n",arr[i].nama);
        printf("Score : %d\n",arr[i].nilai);
    }
    
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

void bubble_sort_struct(Mahasiswa arr[],int n){
    for (int i = 0; i < n; i++)
    {
        
       // buat loop kedua buat ngecek masing" index 
       // tidak rerjadi swap, break
       int flag = 0;
       for (int j = 0; j < n-1-i; j++)
       {
           //ngebandingin
           if (strcmp(arr[j].nama , arr[j+1].nama) > 0){
               //tukar
               Mahasiswa temp = arr[j];
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
void selection_sort_struct(Mahasiswa arr[],int n){
    // loop untuk n-1 kali
    for (int i = 0; i < n-1; i++)
    {
        //set minimym =  arr[i]
        int min = i ;
        // cek index yang belum di sort
        for (int j = i+1; j < n; j++)
        {
            // compare
            if(arr[j].nilai < arr[min].nilai){
                min = j;
            }
        }
        // swap aar[i] sama min yang baru
        Mahasiswa temp = arr[i];
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

void insertion_sort_struct(Mahasiswa arr[],int n){
    // loop dari index i sampe n-1
    for (int i = 1; i < n; i++)
    {
        //set curr indexnya jadi i (extract current index)
        Mahasiswa curr = arr [i];
        int j;
        //cek belakang index
        for (j = i - 1; j >= 0; j--)
        {
            if (curr.nilai < arr[j].nilai){
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

// void insertion_sort(int arr[],int n){
//   /*
//   cek apakah belakangnya lebih besar 
//   kalau iya, akan mundur 
//   dan cek terus sampai mentok
//   */

//   for(int i = 1; i<n; i++){
//     int temp = arr[i];
//     int j = i-1;
//     while(arr[j]>temp && j>=0){
//       arr[j+1]=arr[j];
//       j--;
//     }
//       arr[j+1] = temp;
//   }
// }





int main(){

    // Mahasiswa arr[4];
    // strcpy(arr[0].nama, "Anderson");
    // arr[0].nilai = 84;
    // strcpy(arr[1].nama, "Peter");
    // arr[1].nilai = 86;
    // strcpy(arr[2].nama, "Vincent");
    // arr[2].nilai = 90;
    // strcpy(arr[3].nama, "Felix");
    // arr[3].nilai = 92;
    int arr[] = {29,10,14,37,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    print_arr(arr,n);
    // insertion_sort_struct(arr,4);
    // print_arr_struct(arr,n);
    











    return 0;
}