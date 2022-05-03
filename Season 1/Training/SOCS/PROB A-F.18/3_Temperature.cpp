#include <stdio.h>
#include <string.h>

int N = 0;

struct kota{
    char kota[1001], derajat[2];
    float suhu, temp;
};

kota list_kota[101];
void read(){
    FILE *read;
	read = fopen("testdata.in", "r");

	while(!feof(read)){
		fscanf(read, "%[^#]#%f#%c\n", list_kota[N].kota, &list_kota[N].suhu, list_kota[N].derajat);
		N++;
	}
	
	fclose(read);
}

// void swap(kota *x, kota *y){
//     kota tempS = *x;
//     *x = *y;
//     *y = tempS;
// }

int main(){

    read();

    for(int i = 0; i < N; i++){
        list_kota[i].temp = list_kota[i].suhu;
    }

    for(int j = 0; j < N; j++){
        if(strcmp(list_kota[j].derajat, "F") == 0){
            list_kota[j].temp = (list_kota[j].suhu - 32) * 5 / 9;
        }
    }

    for(int k = 0; k < N - 1; k++){
        for(int l = 0; l < N - k - 1; l++){
            kota temp;
            if(list_kota[l].temp > list_kota[l + 1].temp){
                temp = list_kota[l];
                list_kota[l] = list_kota[l+1];
                list_kota[l+1] = temp;
            }

            if(list_kota[l].temp == list_kota[l + 1].temp){
                if(strcmp(list_kota[l].kota, list_kota[l + 1].kota) > 0){
                    temp = list_kota[l];
                    list_kota[l] = list_kota[l+1];
                    list_kota[l+1] = temp;
                }
            }
        }
    }

    for(int m = 0; m < N; m++){
        printf("%s is %.2f%s\n", list_kota[m].kota, list_kota[m].suhu, list_kota[m].derajat);
    }

    return 0;
}