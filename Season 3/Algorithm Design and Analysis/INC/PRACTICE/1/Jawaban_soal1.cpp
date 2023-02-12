#include <stdio.h>

int main(){
	int isi,tp;
	int arr_1[1009] = {};
	int arr_2[1009] = {};
	int hasil = 0;
	
    scanf("%d" ,&isi);
	for(int i=0; i<isi; i++){
		scanf("%d", &arr_1[i]);
		
        if(arr_1[i] > 0){
			arr_2[arr_1[i]]++;
		}
		
        if(arr_1[i] < 0 && arr_2[arr_1[i]*-1] <= 0){
			hasil++;
			arr_2[arr_1[i]*-1]--;
		}
        
        else if(arr_1[i] == 0){
        	tp++;
		}
	}
	printf("%d\n", hasil);
}
