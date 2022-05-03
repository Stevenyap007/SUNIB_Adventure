#include <stdio.h>

struct dosen{
	char kodeDosen[30];
	char namaDosen[30];
	char jenisKelaminD[30];
	int jumlahMahasiswa;
};

struct keluarga{
	char namaAyah[30];
	char namaIbu[30];
	char jumlahSaudara;
};

struct mahasiswa {
	char kodeMahasiswa[30];
	char namaMahasiswa[30];
	char jenisKelaminM[30];
	keluarga detil;
};

int main(){
	
	int N, T;
	scanf("%d", &N);
	
	dosen D[N];
	mahasiswa M[100][100];
	
	for (int i = 0; i < N; i++){
		scanf(" %s", D[i].kodeDosen);
		scanf(" %s", D[i].namaDosen);
		scanf(" %s", D[i].jenisKelaminD);
		scanf("%d", &D[i].jumlahMahasiswa);
		
		T = D[i].jumlahMahasiswa;
		M[i][T];
		
		for(int j = 0; j < T; j++){
			scanf(" %s", M[i][j].kodeMahasiswa);
			scanf(" %s", M[i][j].namaMahasiswa);
			scanf(" %s", M[i][j].jenisKelaminM);
			scanf(" %s", M[i][j].detil.namaAyah);
			scanf(" %s", M[i][j].detil.namaIbu);
			scanf("%d", &M[i][j].detil.jumlahSaudara);
		}
	}
	
	int K;
	scanf("%d", &K);
	
	printf("Kode Dosen: %s\n", D[K - 1].kodeDosen);
	printf("Nama Dosen: %s\n", D[K - 1].namaDosen);
	printf("Gender Dosen: %s\n", D[K - 1].jenisKelaminD);
	printf("Jumlah Mahasiswa: %d\n", D[K - 1].jumlahMahasiswa);
	
	T = D[K - 1].jumlahMahasiswa;
	for(int k = 0; k < T; k++){
		printf("Kode Mahasiswa: %s\n", M[K - 1][k].kodeMahasiswa);
		printf("Nama Mahasiswa: %s\n", M[K - 1][k].namaMahasiswa);
		printf("Gender Mahasiswa: %s\n", M[K - 1][k].jenisKelaminM);
		printf("Nama Ayah: %s\n", M[K - 1][k].detil.namaAyah);
		printf("Nama Ibu: %s\n", M[K - 1][k].detil.namaIbu);
		printf("Jumlah Saudara Kandung: %d\n", M[K - 1][k].detil.jumlahSaudara);
	}
}
