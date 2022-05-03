#include <stdio.h>
#include <stdlib.h>

int mat1[100][100], mat2[100][100];

void output(int sisi, int area1, int area2){
	system("cls");
	
	printf("Matrix 1:\n");
	for(int i=1; i<=sisi; i++){
		for(int j=1; j<=sisi; j++){
			printf("%d ", mat1[i][j]);
		}
		puts("");
	}
	
	printf("Matrix 2:\n");
	for(int i=1; i<=sisi; i++){
		for(int j=1; j<=sisi; j++){
			printf("%d ", mat2[i][j]);
		}
		puts("");
	}
	
	if(area1 == area2){
		printf("Object 1 and 2 has the same size\n");
	}else if(area1 > area2){
		printf("Object 1 is bigger\n");
	}else{
		printf("Object 2 is bigger\n");
	}
}

void check(int sisi){
	int largest = 0, smallest = sisi, count1 = 0, count2 = 0;
	
	for(int i=1; i<=sisi; i++){
		for(int j=1; j<=sisi; j++){
			if(mat1[i][j] == 1){
				if(j > largest){
					largest = j;
				}
				
				if(j < smallest){
					smallest = j;
				}
			}
		}
		
		count1 = count1 + (largest - smallest + 1);
	}
	
	largest = 0;
	smallest = sisi;
	
	for(int i=1; i<=sisi; i++){
		for(int j=1; j<=sisi; j++){
			if(mat2[i][j] == 1){
				if(j > largest){
					largest = j;
				}
				
				if(j < smallest){
					smallest = j;
				}
			}
		}
		
		count2 = count2 + (largest - smallest + 1);
	}
	
	output(sisi, count1, count2);
}

void input(int sisi){
	printf("Sisi matriks: ");
	scanf("%d", &sisi);
	getchar();
	
	system("cls");
	
	printf("Input matrix1:\n");
	for(int i=1; i<=sisi; i++){
		for(int j=1; j<=sisi; j++){
			scanf("%d", &mat1[i][j]);
			getchar();
		}	
	}
	
	printf("Input matrix2:\n");
	for(int i=1; i<=sisi; i++){
		for(int j=1; j<=sisi; j++){
			scanf("%d", &mat2[i][j]);
			getchar();
		}	
	}
	
	check(sisi);
}

int main(){
	int sisi;
	
	input(sisi);
	
	return 0;
}
