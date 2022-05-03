#include <stdio.h>
#include <string.h>

struct kaset{
    char nama[110];
};
kaset mahasiswa[110];

void bubble_sort(kaset arr[],int batas){
    for (int i = 0; i < batas; i++)
    {
        for (int j = 0; j < batas - 1 - i; j++)
        {
            if(strcmp(mahasiswa[j].nama,mahasiswa[j+1].nama) > 0){
                kaset temp = mahasiswa[j];
                mahasiswa[j] = mahasiswa[j+1];
                mahasiswa[j+1] = temp;
            }
        }
        
    }
    
}

int main(){
    
    int T;
    scanf("%d",&T);

    for (int i = 0; i < T; i++)
    {
        int kaset;
        int target;
        scanf("%d %d",&kaset,&target);
        mahasiswa[kaset];
        for (int j = 0; j < kaset; j++)
        {
            scanf("%s",&mahasiswa[j].nama);
        }
        bubble_sort(mahasiswa,kaset);
        printf("Case #%d: %s\n",i+1,mahasiswa[target-1].nama);
        
    }
    












    return 0;
}