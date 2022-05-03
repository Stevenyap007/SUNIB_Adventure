#include<stdio.h>
#include<string.h>

void bubble_Sort(char arr[][100], int n){
	
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			
			char temp[10];
			if(strcmp(arr[i], arr[j]) > 0){
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
			
		}
	}
	
}

void print(char arr[][100], int n){
	
	for(int i=0; i<n; i++){
		printf("%s ", arr[i]);
	}
	printf("\n");
	
}

int main(){
	
	
	char name[][100] = {"Ali", "Ani", "Tono", "Bayu", "Amir", "Ani", "Budi", "Tini", "Ucok", "Paijo"};
					   
	int size = sizeof(name) / sizeof(name[0]);
    bubble_Sort(name, size);
	
	print(name, size);
	
	return 0;
}