#include <stdio.h>
#include <string.h>

struct data{
	char judul[10];
	int waktu;
};

data jadwal[10];

void swap(data *a, data *b){
	data t = *a;
	*a = *b;
	*b = t;	
}

void bubble(int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(jadwal[j].waktu > jadwal[j+1].waktu){
				swap(&jadwal[j], &jadwal[j+1]);
			} else if(jadwal[j].waktu == jadwal[j+1].waktu){
				if(strcmp (jadwal[j].judul, jadwal[j+1].judul) > 0){
					swap(&jadwal[j], &jadwal[j+1]);
				}
			}
		}
	}	
}

int main(){
	
	int N;
	scanf("%d", &N);
	
	data S[N];
	for(int i = 0; i < N; i++){
		scanf(" %s %d", &jadwal[i].judul, &jadwal[i].waktu);
	}
	
	bubble(N);
	
	for(int i = 0; i < N; i++){
		printf("%s\n", &jadwal[i].judul);
	}
	
	return 0;
}