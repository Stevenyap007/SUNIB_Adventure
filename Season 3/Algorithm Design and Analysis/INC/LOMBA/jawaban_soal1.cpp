#include<iostream>
#include<algorithm>
using namespace std;

void merge(int arr[],int kiri,int tengah,int kanan){
  int no=tengah-kiri+1;
  int yes=kanan-tengah;
  int L[no],R[yes];

	for(int i=0;i<no;i++){
    	L[i]=arr[kiri+i];
  	}
	for(int j=0;j<yes;j++){
    	R[j]=arr[tengah+1+j];
  	}

  	int i=0,j=0,k=kiri;
  	
  	while(i<no && j<yes){
    	if(L[i] <= R[j]){
      		arr[k] = L[i];
      		i++;
    	}
    	else{
      		arr[k]=R[j];
     	 	j++;
    	}
    	k++;
  	}
  	
  	while(i<no){
   	 	arr[k]=L[i];
    	i++;
    	k++;
  	}
  	
  	while(j<yes){
    	arr[k]=R[j];
    	j++;
    	k++;
  	}
}

void sorting(int arr[], int kiri, int kanan){
  	if (kiri<kanan){
    	int tengah=kiri+(kanan-kiri)/2;
    	sorting(arr,kiri,tengah);
    	sorting(arr,tengah+1,kanan);
    	merge(arr,kiri,tengah,kanan);
    }
}

int main() {
	int anak, rate,count = 0, max = -1;
	scanf("%d %d", &anak, &rate);
    getchar();

	int arr[200] = {};
	for(int i=0; i<anak; i++) {
		scanf("%d", &arr[i]);
	}

    sorting(arr,0,anak-1);
	
	for(int i=0; i<anak-2; i++){
		for(int j=i+1; j<anak-1; j++) {
			if(i == j){
                continue;
            } 

			for(int k=j+1; k<anak; k++) {
				if(k==i || k == j){
                    continue;
                } 

				int temp = arr[k] - arr[i];

				if(temp > rate){
                    break;
                } 
				count = count+1;
				max = arr[i] + arr[j] + arr[k];
			}
		}
	}

	if(count == 0){
		printf("-1\n");
	}else{
		printf("%d %d\n", count, max);
	}

}
