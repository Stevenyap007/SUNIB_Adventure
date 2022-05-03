#include <stdio.h>
#include <string.h>

int N;

struct Tumbuhan{
    char name[41];
    int num;
};

Tumbuhan arr_tanaman[1001];

void read(){
	FILE *read;
	read = fopen("testdata.in", "r");

	fscanf(read, "%d", &N);
	int idx = 0;
	while(idx <= N){
		fscanf(read, "%d#%[^\n]\n", &arr_tanaman[idx].num, arr_tanaman[idx].name);
		idx++;
	}
	
	fclose(read);
}

int main(){
	
	read();

	char tempName[41];
	int tempNum;

	for(int i = 0; i < N - 1; i++){
		for(int j = 0; j < N - i - 1; j++){
			if(strcmp(arr_tanaman[j].name, arr_tanaman[j + 1].name) > 0){
				// strcpy(tempName, arr_tanaman[j].name);
				// tempNum = arr_tanaman[j].num;
				
				// strcpy(arr_tanaman[j].name, arr_tanaman[j + 1].name);
				// arr_tanaman[j].num = arr_tanaman[j + 1].num;
				
				// strcpy(arr_tanaman[j + 1].name, tempName);
				// arr_tanaman[j + 1].num = tempNum;

                Tumbuhan temp;
                temp = arr_tanaman[j];
                arr_tanaman[j] = arr_tanaman[j+1];
                arr_tanaman[j+1] = temp;
			}
		}
	}

    for(int i = 0; i < N; i++){
        printf("%d %s\n", arr_tanaman[i].num, arr_tanaman[i].name);
    }
    
    return 0;
}