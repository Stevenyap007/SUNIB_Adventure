#include <stdio.h>

struct Mahasiswa
{
    char Nama[105];
    char NIM[10];
    int Umur;
    char KodePos[7];
    char Tempat_Lahir[105];
    char Tanggal_Lahir[105];
    char Almamater_SMA[105];
    int Jumlah_Saudara_Kandung;
    int Tinggi_Badan;
    char Nomor_rekening[10];
};


int main (){

    int T;
    scanf("%d",&T);

    Mahasiswa count[T];

    for (int i = 0; i < T; i++)
    {
        scanf("%s",&count[i].Nama);
        scanf("%s",&count[i].NIM);
        scanf("%d",&count[i].Umur);
        scanf("%s",&count[i].KodePos);
        scanf("%s",&count[i].Tempat_Lahir);
        scanf("%s",&count[i].Tanggal_Lahir);
        scanf(" %101[^\n]",&count[i].Almamater_SMA);
        scanf("%d",&count[i].Jumlah_Saudara_Kandung);
        scanf("%d",&count[i].Tinggi_Badan);
        scanf("%s",&count[i].Nomor_rekening);
    }

    for (int i = 0; i < T; i++)
    {
        printf("Mahasiswa ke-%d:\n", i + 1);
        printf("Nama: %s\n",count[i].Nama);
        printf("NIM: %s\n",count[i].NIM);
        printf("Umur: %d\n",count[i].Umur);
        printf("Kode Pos: %s\n",count[i].KodePos);
        printf("Tempat Lahir: %s\n",count[i].Tempat_Lahir);
        printf("Tanggal Lahir: %s\n",count[i].Tanggal_Lahir);
        printf("Almamater SMA: %s\n",count[i].Almamater_SMA);
        printf("Jumlah Saudara Kandung: %d\n",count[i].Jumlah_Saudara_Kandung);
        printf("Tinggi Badan: %d\n",count[i].Tinggi_Badan);
        printf("NOMOR REKENING: %s\n",count[i].Nomor_rekening);
    }
    










    return 0;
}