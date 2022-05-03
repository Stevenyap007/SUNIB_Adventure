#include<stdio.h>
#include<string.h>

struct Friends{
	char nama[25];
	char No_telp[14];
	char alamat[25];
};
struct Friends data[30];
int num, count = 0;
char keyword[20];

void sort( struct Friends data[], int b){	
	int i, j, low, temp;
	for( i = 0; i < b - 1; i++){
		low = i;
		for( j = i + 1; j < b; j++){
			if( strcmp(data[low].nama, data[j].nama) > 0){
				struct Friends temp = data[i];
				data[i]   = data[low];
				data[low] = temp;
			}
		}
	}
}
void add(){

	printf("How many friends do you want to input ?");
	scanf(" %d", &num); 
	while( num--){
		printf("Name\t\t: ");
		scanf(" %[^\n]",data[count].nama);		
		printf("Phone Number\t: ");
		scanf(" %[^\n]",data[count].No_telp); 		
		printf("Address\t\t: ");
		scanf(" %[^\n]",data[count].alamat);	
		printf("\n");
		count++;
	}
}
void find(){

	printf("Please input the keyword : ");
	scanf(" %[^\n]", keyword);	
	
	sort( data, count);
	
	printf("\n");
	int found = 0, k, l;
	for( k = 0; k < count; k++){	
		int hitung = 1;
		for( l = 0; l < strlen(keyword); l++){
			if( keyword[l] != data[k].nama[l]){
				hitung = 0;
				break;
			}
		}
		if( hitung == 1){
			found = 1;
			printf("Nama\t\t: %s\n", data[k].nama);
			printf("Phone Number\t: %s\n", data[k].No_telp);
			printf("Address\t\t: %s", data[k].alamat);
			printf("\n\n");
		}
	}
    if(found == 0){
			printf("Data Not Exist\n");
	}
	
	}
int main(){
	
	int pilihan;
	while(pilihan!=3){
	
		printf("\t\t Hello Riri, Welcome \n\n");
		printf("1. Input new contact\n");
		printf("2. Find your contact\n");
		printf("3. Exit\n\n");
		printf("Please Enter your choice : ");
		scanf("%d", &pilihan); 
		
		switch(pilihan){
			case 1:
				add();
				break;
			case 2:
				find();
				break;
			case 3:
 				return 0;
		}
	}
    return 0;
}

/*
7
Dini Noviani	081225224336	Pekalongan, Jawa Tengah
Dini Maryati	081225224337	Semarang, Jawa Tengah
Fahri	        081225224338	Jayapura, Papua
Fahrur	        081227224336	Sintang, Kalimantan Barat
Zafir	        081235294339	Samarinda, Kalimantan Timur
Ruben	        081205220336	Malang, Jawa Timur
Tria	        081225224336	Bandung, Jawa Barat
*/
