#include <stdio.h>

struct data
{
    char NIM[25];
    char nama[110];
    int umur;
};

int main(){
    data mahasiswa[1020];
    int N,Q,urutan;

    scanf("%d",&N);
    mahasiswa[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%s",&mahasiswa[i].NIM);
        getchar();
        scanf("%[^\n]",&mahasiswa[i].nama);
        getchar();
        scanf("%d",&mahasiswa[i].umur);
        getchar();
    }

    scanf("%d",&Q);
    for (int j = 0; j < Q; j++)
    {
        scanf("%d",&urutan);
        printf("Query #%d:\n",j+1);
        printf("ID: %s\n",mahasiswa[urutan-1].NIM);
        printf("Name: %s\n",mahasiswa[urutan-1].nama);
        printf("Age: %d\n",mahasiswa[urutan-1].umur);
    }
    



    return 0;
}