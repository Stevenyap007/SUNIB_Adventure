#include <stdio.h>

int count(int arr[], int N){
	
	int count = 0;
	
	for(int i = 0; i < N; i++){
		int j = 0;
		for(j = 0; j < i; j++){
			if(arr[i] == arr[j]){
				break;
			}
		}
		
		if(i == j){
		count++;
		}
	}
	
	return count;
}

int main(){
	
	int N;
	scanf("%d", &N);
	
	int arr[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	printf("%d\n", count(arr, N));
	
	return 0;
}