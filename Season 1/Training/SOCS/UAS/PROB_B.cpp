#include <stdio.h>

struct barang{
    long int alat_musik[100];
    long int total_alat_musik[100];
    char nama_alat_musik[100][100];
    long int harga_alat_musik[100];
    // struct untuk mendata barang
};
barang pesanan[100];
long int total[100];
long int C;

void read(){
    long int F;
    FILE *read;
	read = fopen("testdata.in", "r");
    // membaca file testdata.in

	while(!feof(read)){
		fscanf(read,"%ld\n", &C);
        pesanan[C];
        total[C];
        for (int i = 0; i < C; i++)
        {
            total[i] = 0;
            fscanf(read,"%ld\n", &F);
            pesanan[i].alat_musik[F];
            for (int j = 0; j < F; j++)
            {
                fscanf(read,"%ld#%[^@]@%ld\n", &pesanan[i].total_alat_musik[j],&pesanan[i].nama_alat_musik[j],&pesanan[i].harga_alat_musik[j]);
                total[i] += (pesanan[i].total_alat_musik[j] * pesanan[i].harga_alat_musik[j]);
            }
            
        }
            //mengscan dan menjumlahkan total harga
	}
	
	fclose(read);

}


int main(){

    read();

    for (int k = 0; k < C; k++)
    {
        printf("Customer #%ld: Rp %ld\n",k+1,total[k]-total[k]*15/100);
        //print harga setalh diskon
    }
    




    return 0;
}