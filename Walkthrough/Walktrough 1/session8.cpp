#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void writeFile(char namaMahasiswa[100][100], int umur[100], int size){
	//buka file
	FILE* ptrFile = fopen("mahasiswa.txt","w");
	
	for(int i= 0; i < size; i++){
		fprintf(ptrFile, "%s#%d\n", namaMahasiswa[i],umur[i]);
	}
	
	fclose(ptrFile);
}

void readFile(){
	FILE* ptrFile = fopen("mahasiswa.txt", "r");
	
	if (ptrFile == NULL){
		puts("File does not exists");
	} else {
		char namaMahasiswa[100];
		int umur;
		
		while(!feof(ptrFile)){
			fscanf(ptrFile, "%[^#]#%d\n", &namaMahasiswa, &umur);
		printf("%s: %d\n",namaMahasiswa, umur);	
				
		}
	
	}
	
		fclose(ptrFile);

}


struct Mahasiswa{
	char nama[100];
	int umur;
	int nim;
} mhs1;// cara untuk membuat variable

struct Mahasiswa mhs2;//cara 2 untuk membuat variabel

struct Mahasiswa mhs3[100]; // membuat Array

union Siswa{ // 100
	char nama [100]; // 100 byte
	int umur; // 4 byte
	int nim; // 4 byte
};

/*
nama1,nama2,nama3
*/

int main (){
	
	// Struct -> suatu tipe data yang kita buat sendiri
	// tipe data int, char, bool -> tipe data primitif
	// int number = 0;
	
//	char namaMahasiswa[100][100] = {
//	{"Budi"},
//	{"jono"},
//	{"Bambang"},
//	};
//	
//	int umur[100] = {17,18,19};
//	
//	writeFile(namaMahasiswa, umur, 3);
//
//	readFile();

	// mhs1, mhs2, mhs3
//	strcpy(mhs1.nama,"Budi");
//	mhs1.umur = 10;
//	mhs1.nim = 1231313131;
//
//	strcpy(mhs3[0].nama, "Joni");
//	mhs3[0].umur = 11;
//	mhs3[0].nim = 1231412;
//	
//	printf("%s, %d, %d\n",mhs3[0].nama, mhs3[0].umur, mhs3[0].nim);
	
	
	//setiap kalian melakukan suatu insert data
	//mahasiswa maka kalian harus pesan memorinya lagi
//	struct Mahasiswa* ptrMhs;
//	ptrMhs = (Mahasiswa*) malloc(sizeof(Mahasiswa));
//	strcpy(ptrMhs->nama, "Bambang");
//	ptrMhs->umur = 20;
//	ptrMhs->nim = 12312312;
//
//	printf("%s, %d, %d\n", ptrMhs->nama, ptrMhs->umur, ptrMhs->nim);

	union Siswa s1;
	strcpy(s1.nama, "Andi");
	s1.umur = 20;
	s1.nim = 12314151;
	
	printf("%s, %d, %d\n", s1.nama,s1.umur,s1.nim);






	
	return 0;
}
