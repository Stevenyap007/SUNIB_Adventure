#include <stdio.h>
#include <string.h>

struct data
{
    char nama[50];
    int nomor;
};
data mahasiswa[50];

void bubble_sort(int n){
    
    for (int i = 0; i < n; i++)
    {
        
       // buat loop kedua buat ngecek masing" index 
       // tidak rerjadi swap, break
       for (int j = 0; j < n-1-i; j++)
       {
            data temp;
            char tempnama[50];
            //ngebandingin
            if(mahasiswa[j].nomor < mahasiswa[j+1].nomor){
                temp = mahasiswa[j];
                mahasiswa[j] = mahasiswa[j+1];
                mahasiswa[j+1] = temp;
            }else if (mahasiswa[j].nomor == mahasiswa[j+1].nomor ){
                if(strcmp(mahasiswa[j].nama, mahasiswa[j+1].nama) > 0){
                strcpy(tempnama, mahasiswa[j].nama);
                strcpy(mahasiswa[j].nama, mahasiswa[j+1].nama);
                strcpy(mahasiswa[j+1].nama, tempnama);
            }
            }

        }
    }
}


int main(){

    int T;
    int N;
    scanf("%d",&T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d",&N);
        mahasiswa[N];
        for (int j = 0; j < N; j++)
        {
            scanf(" %[^#]#%d",&mahasiswa[j].nama,&mahasiswa[j].nomor);
        }
        
        bubble_sort(N);


        printf("Case #%d:\n",i+1);
        for (int k = 0; k < N; k++)
        {
            printf("%s - %d\n",mahasiswa[k].nama,mahasiswa[k].nomor);
        }
        
    }
    











    return 0;
}