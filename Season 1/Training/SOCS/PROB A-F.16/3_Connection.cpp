#include <stdio.h>

struct Dosen
{
    char Kode_dosen[30];
    char Nama_dosen[30];
    char Jenis_KD[30];
    int Jumlah_mahasiswa;
};

struct Keluarga
{
    char Nama_ayah[30];
    char Nama_ibu[30];
    int Jumlah_saudara;
};

struct Mahasiswa
{
    char Kode_Mahasiswa[30];
    char Nama_Mahasiswa[30];
    char Jenis_KM[30];
    Keluarga desc;
};


int  main(){

    int N;
    int T;

    scanf("%d",&N);
    Dosen D_count[N];
    Mahasiswa M_count[100][100];

    for (int i = 0; i < N; i++)
    {
        scanf(" %s",&D_count[i].Kode_dosen);
        scanf(" %s",&D_count[i].Nama_dosen);
        scanf(" %s",&D_count[i].Jenis_KD);
        scanf("%d",&D_count[i].Jumlah_mahasiswa);

        T = D_count[i].Jumlah_mahasiswa;
        M_count[i][T];

        for (int j = 0; j < T; j++)
        {
            scanf(" %s",&M_count[i][j].Kode_Mahasiswa);
            scanf(" %s",&M_count[i][j].Nama_Mahasiswa);
            scanf(" %s",&M_count[i][j].Jenis_KM);
            scanf(" %s",&M_count[i][j].desc.Nama_ayah);
            scanf(" %s",&M_count[i][j].desc.Nama_ibu);
            scanf("%d",&M_count[i][j].desc.Jumlah_saudara);
        }   
    }

    int K;
    scanf("%d",&K);

    printf("Kode Dosen: %s\n",D_count[K-1].Kode_dosen);
    printf("Nama Dosen: %s\n",D_count[K-1].Nama_dosen);
    printf("Gender Dosen: %s\n",D_count[K-1].Jenis_KD);
    printf("Jumlah Mahasiswa: %d\n",D_count[K-1].Jumlah_mahasiswa);

    T = D_count[K-1].Jumlah_mahasiswa;
    for (int k = 0; k < T; k++)
    {
        printf("Kode Mahasiswa: %s\n",M_count[K-1][k].Kode_Mahasiswa);
        printf("Nama Mahasiswa: %s\n",M_count[K-1][k].Nama_Mahasiswa);
        printf("Gender Mahasiswa: %s\n",M_count[K-1][k].Jenis_KM);
        printf("Nama Ayah: %s\n",M_count[K-1][k].desc.Nama_ayah);
        printf("Nama Ibu: %s\n",M_count[K-1][k].desc.Nama_ibu);
        printf("Jumlah Saudara Kandung: %d\n",M_count[K-1][k].desc.Jumlah_saudara);
    }
    
    







    return 0;
}