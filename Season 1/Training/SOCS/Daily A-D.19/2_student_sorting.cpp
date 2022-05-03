#include <stdio.h>
#include <string.h>

struct mahasiswa
{
    char nama[50];
    char NIM[15];
};
mahasiswa data[1000];

int N;
void scan_file(){
    int index;
    FILE *read;
    read = fopen("testdata.in","r");

    fscanf(read,"%d",&N);
    while(index < N){
        fscanf(read,"%s %s\n",data[index].NIM,data[index].nama);
        index++;
    }
     
    fclose(read);
}



int main(){

    scan_file();
    mahasiswa temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if(strcmp(data[j].NIM , data[j+1].NIM)>0){
                temp = data[j];
                data [j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

    for (int k = 0; k < N; k++)
    {
        printf("%s %s\n",data[k].NIM,data[k].nama);
    }
    
    



    return 0;
}