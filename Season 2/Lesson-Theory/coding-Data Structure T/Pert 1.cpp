//Variable and Pointer
/*#include <stdio.h>

void swap (int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void angka(){
	int a=5;
	int b=10;
	printf("\na= %d, b= %d",a,b);
	swap(&a,&b);
	printf("\na= %d, b= %d",a,b);
}

int main(){
	int x=10;
	int *ptr=&x;
	
	
	printf("X= %d",x);
	printf("\n*ptr= %d",*ptr);
	printf("\nptr= %d",ptr);
	
	angka();
	*ptr=30;
	printf("\nX= %d",x);	
	return 0;
}*/

// Array
#include <stdio.h>

// int x [5]: 0 1 2 3 4
// int x [5][5]
//     0 1 2 3 4
// 0
// 1
// 2
// 3
// 4

// char nama[6]
//  0  1  2  3  4  5  6
//  p  u  t  i

int main(){
	char nama [100][100];
	float ipk [100];
	int n,i;
	
	printf("Jumlah Mahasiswa: ");
	scanf("%d",&n); getchar();
	
	for (int i=0;i<n; i++){
		printf("\nNama mahasiswa ke %d: ",i+1);
		scanf("%s", nama[i]);
		printf("IPK mahasiswa ke %d: ",i+1);
		scanf("%f",&ipk[i]);getchar();
		
	}
	
	printf("\nHasilnya....");
	for (int i=0;i<n;i++){
		printf("\nNama mahasiswa ke %d: %s",i+1,nama[i]);
		printf("\nIPK mahasiswa ke %d: %.2f",i+1,ipk[i]);
	}
	
	return 0;
}










