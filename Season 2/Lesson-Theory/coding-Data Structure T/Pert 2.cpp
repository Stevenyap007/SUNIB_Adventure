//Basic Struct

/*#include <stdio.h>
#include <string.h>

struct buah{
	char warna[100];
	char bentuk[100];
	float jumlah;
	int harga;	
};

int main(){
	struct buah jeruk;
	struct buah apel;
	strcpy(jeruk.warna,"kuning");
	strcpy(jeruk.bentuk,"bulat");
	jeruk.jumlah=3;
	jeruk.harga=20000;
	
	printf("\nBerikut adalah data jeruk..");
	printf("\nWarna: %s",jeruk.warna);
	printf("\nBentuk: %s",jeruk.bentuk);
	printf("\nJumlah: %.2f",jeruk.jumlah);
	printf("\nHarga: %d", jeruk.harga);

	printf("\n\nMasukkan data Apel");
	printf("\nWarna: ");
	scanf("%s",apel.warna);getchar();
	printf("\nBentuk: ");
	scanf("%s",apel.bentuk);getchar();
	printf("\nJumlah: ");
	scanf("%f",&apel.jumlah);getchar();
	printf("\nHarga: ");
	scanf("%d",&apel.harga);getchar();
	
	printf("\nBerikut adalah data apel..");
	printf("\nWarna: %s",apel.warna);
	printf("\nBentuk: %s",apel.bentuk);
	printf("\nJumlah: %.2f",apel.jumlah);
	printf("\nHarga: %d", apel.harga);
	
	
	
	return 0;
}*/










//Nested struct

/*#include <stdio.h>
#include <string.h>

struct stok{
	char gudang [100];
	float jumlah;
	int harga;	
};

struct buah{
	char warna[100];
	char bentuk[100];
	struct stok stk;
};

int main(){
	struct buah jeruk;
	struct buah apel;
	strcpy(jeruk.warna,"kuning");
	strcpy(jeruk.bentuk,"bulat");
	strcpy(jeruk.stk.gudang,"Pluit");
	jeruk.stk.jumlah=3;
	jeruk.stk.harga=20000;
	
	printf("\nBerikut adalah data jeruk..");
	printf("\nWarna: %s",jeruk.warna);
	printf("\nBentuk: %s",jeruk.bentuk);
	printf("\nGudang: %s",jeruk.stk.gudang);
	printf("\nJumlah: %.2f",jeruk.stk.jumlah);
	printf("\nHarga: %d", jeruk.stk.harga);

	printf("\n\nMasukkan data Apel");
	printf("\nWarna: ");
	scanf("%s",apel.warna);getchar();
	printf("\nBentuk: ");
	scanf("%s",apel.bentuk);getchar();
	printf("\nGudang: ");
	scanf("%s",apel.stk.gudang);
	printf("\nJumlah: ");
	scanf("%f",&apel.stk.jumlah);getchar();
	printf("\nHarga: ");
	scanf("%d",&apel.stk.harga);getchar();
	
	printf("\nBerikut adalah data apel..");
	printf("\nWarna: %s",apel.warna);
	printf("\nBentuk: %s",apel.bentuk);
	printf("\nGudang: %s",apel.stk.gudang);
	printf("\nJumlah: %.2f",apel.stk.jumlah);
	printf("\nHarga: %d", apel.stk.harga);
	
	
	
	return 0;
}*/


// Array of struct

#include <stdio.h>
#include <string.h>

struct stok{
	char gudang [100];
	float jumlah;
	int harga;	
};

struct buah{
	char warna[100];
	char bentuk[100];
	struct stok stk;
};

int main(){
	struct buah jeruk;
	struct buah apel[5];
	int n,i;
	strcpy(jeruk.warna,"kuning");
	strcpy(jeruk.bentuk,"bulat");
	strcpy(jeruk.stk.gudang,"Pluit");
	jeruk.stk.jumlah=3;
	jeruk.stk.harga=20000;
	
	printf("\nBerikut adalah data jeruk..");
	printf("\nWarna: %s",jeruk.warna);
	printf("\nBentuk: %s",jeruk.bentuk);
	printf("\nGudang: %s",jeruk.stk.gudang);
	printf("\nJumlah: %.2f",jeruk.stk.jumlah);
	printf("\nHarga: %d", jeruk.stk.harga);

	printf("\nJumlah Jenis Apel: ");
	scanf("%d",&n);
	printf("\n\nMasukkan data Apel");
	for (i=0;i<n;i++){
		printf("\nWarna: ");
		scanf("%s",apel[i].warna);getchar();
		printf("\nBentuk: ");
		scanf("%s",apel[i].bentuk);getchar();
		printf("\nGudang: ");
		scanf("%s",apel[i].stk.gudang);
		printf("\nJumlah: ");
		scanf("%f",&apel[i].stk.jumlah);getchar();
		printf("\nHarga: ");
		scanf("%d",&apel[i].stk.harga);getchar();
	}

	printf("\nBerikut adalah data apel..");
	for (i=0;i<n;i++){
		printf("\nWarna: %s",apel[i].warna);
		printf("\nBentuk: %s",apel[i].bentuk);
		printf("\nGudang: %s",apel[i].stk.gudang);
		printf("\nJumlah: %.2f",apel[i].stk.jumlah);
		printf("\nHarga: %d", apel[i].stk.harga);		
	}

	
	return 0;
}











